# Seconda-BuildWeek-EPICODE-
Progetto di Ethical Hacking e Penetration Testing: exploit di vulnerabilità Web (SQLi manuale, XSS), analisi Buffer Overflow e compromissione di servizi su sistemi Linux e Windows tramite Metasploit.
# 🔐 Ethical Hacking & Penetration Testing Lab - Epicode Build Week

Questo repository raccoglie le attività svolte durante la seconda Build Week del corso **Cybersecurity Specialist** di Epicode. Il progetto simula uno scenario di **Red Teaming** e **Vulnerability Assessment** su diverse macchine target.

## 🎯 Obiettivi del Progetto
L'obiettivo principale è stato identificare, analizzare e sfruttare vulnerabilità critiche in ambienti controllati, passando da attacchi alle Web Application fino alla compromissione completa di sistemi server e desktop.

## 🛠 Tech Stack & Tools
* **Attacker Machine:** Kali Linux
* **Target Machines:** Metasploitable 2, Windows 10, DVWA (Damn Vulnerable Web App)
* **Exploitation Framework:** Metasploit (MSFConsole, Meterpreter)
* **Web Analysis:** Burp Suite
* **Scanning:** Nessus, Nmap
* **Linguaggi:** C (Analisi BOF), Python/Bash

## ⚡ Scenari e Attività Svolte

### 1. Web Application Security (DVWA)
Analisi manuale delle vulnerabilità OWASP Top 10:
* **SQL Injection (SQLi):** Exploitation manuale (senza sqlmap) per l'estrazione di credenziali utente dal database.
* **Cross-Site Scripting (XSS):** Esecuzione di attacchi XSS persistenti per il furto di sessione (Cookie Stealing) con invio dati a un listener esterno.

### 2. System Exploitation & Low Level
* **Buffer Overflow (BOF):** Analisi di un programma in C vulnerabile, studio della segmentazione di memoria e creazione di un exploit per causare un errore di segmentazione manipolando l'input utente.
* **Linux Exploitation:** Vulnerability Scanning con Nessus su Metasploitable e sfruttamento della vulnerabilità Samba (Porta 445) tramite script `usermap_script` per ottenere una shell remota.

### 3. Windows & Post-Exploitation
* **Windows 10 Attack:** Exploitation del servizio **Apache Tomcat** tramite Metasploit per ottenere una sessione Meterpreter.
* **Post-Exploitation:** Enumerazione del sistema target (VM check, config di rete), verifica periferiche (Webcam) e cattura screenshot del desktop vittima.

## ⚠️ Disclaimer
*Questo progetto è stato realizzato esclusivamente a scopo didattico in un ambiente di laboratorio isolato e controllato. Le tecniche descritte sono state applicate su macchine virtuali appositamente configurate per essere vulnerabili.*

## 👥 Il Team
* Francesco Livi (IO)

* Rosario Papa
* Yari Olmi
* Raffaele Eboli
* Ivan De Vita
* Antonio Gangale
* Michel Di Vincenzo
