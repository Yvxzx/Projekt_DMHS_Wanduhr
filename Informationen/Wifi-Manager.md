# Wifi-Manager

## Wie funktioniert es mit einem ESP32

- Die ESP32 Boots up und prüft, ob es bereits ein WLAN-Netzwerk konfiguriert hat.

- Wenn es WiFi-Anmeldeinformationen hat, verwendet es sie, um sich in ein Netzwerk einzuloggen. Angenommen, es ist erfolgreich, dann ist keine andere Aktion erforderlich, und es kann mit der Skizze beginnen.

- Wenn es keine WLAN-Anmeldeinformationen hat oder wenn sie ungültig sind, stellt es sich stattdessen als Access Point auf. An Access Point bietet das ESP32 ein eigenes WLAN-Netzwerk für andere Geräte, mit denen man sich verbinden kann.

- Es erstellt eine Webseite an einer Adresse von 192.168.4.1. Auf der Webseite gibt es eine Liste der verfügbaren WLAN-Netzwerke, die Sie verbinden können, sowie Textboxen für die Eingabe Ihrer SSID und Passwort. Sie können es auch so konfigurieren, dass zusätzliche Textboxen (oder andere HTML-Elemente) andere Konfigurationsinformationen erhalten, die Sie benötigen.

- Der Benutzer gibt die entsprechenden Informationen ein und drückt die Schaltfläche Speichern. Die Informationen werden an das ESP32 übermittelt.

- Das ESP32 wechselt zurück in den Stationsmodus und versucht, sich mit den mitgelieferten Anmeldeinformationen mit dem gewünschten WLAN-Netzwerk zu verbinden.

- Geht man davon aus, dass der Benutzer die richtigen Anmeldedaten geliefert hat, wird das ESP32 nun mit dem WLAN-Netzwerk verbunden.


## Was passiert

![Flussdiagramm](image-1.png)
- Wenn das ESP anfängt, versucht es, diessid.txt,pass.txtundip.txtDateien zu lesen(1);

- Wenn die Dateien leer sind 2(2) (das erste Mal, wenn Sie die Board ausführen, sind die Dateien leer), wird Ihr Board als Access Point 3(3) festgelegt.

- Mit jedem WLAN-fähigen Gerät mit einem Browser können Sie sich mit dem neu erstellten Access Point verbinden (StandardnameESP-WIFI-MANAGER);

- Nach dem Aufbau einer Verbindung mit dem ESP-WIFI-MANAGER können Sie zur Standard-IP-Adresse gehen 192.168.4.1 eine Webseite zu öffnen, mit der Sie Ihre SSID und Ihr Passwort konfigurieren können (4);

- Die im Formular eingefügte SSID-, Passwort- und IP-Adresse werden in den entsprechenden Dateien gespeichert:ssid.txt, pass.txt, 
undip.txt(5);

- Danach startet der ESP-Vorstand 6 neu (6);

- Dieses Mal sind die Dateien nach dem Neustart nicht leer, so dass das ESP versucht, sich mit dem Netzwerk im Stationsmodus zu verbinden, indem Sie die Einstellungen verwenden, die Sie in das Formular eingefügt haben 7(7).

- Wenn es eine Verbindung aufstellt, wird der Prozess erfolgreich abgeschlossen und Sie können auf die Hauptserverseite zugreifen, die alles tun kann, was Sie wollen (Steuersensoren, Steuerausgänge, Anzeige von Text usw.) (9). Andernfalls wird der Access Point (3), und Sie können auf die Standard-IP-Adresse zugreifen (192.168.4.1) eine weitere SSID/Passwort-Kombination hinzuzufügen.

