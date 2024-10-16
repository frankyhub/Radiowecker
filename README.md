<a name="oben"></a>

<div align="center">

|[:skull:ISSUE](https://github.com/frankyhub/Radiowecker/issues?q=is%3Aissue)|[:speech_balloon: Forum /Discussion](https://github.com/frankyhub/Radiowecker/discussions)|[:grey_question:WiKi](https://github.com/frankyhub/Radiowecker/wiki)||
|--|--|--|--|
| | | | |
|![Static Badge](https://img.shields.io/badge/RepoNr.:-%2080-blue)|<a href="https://github.com/frankyhub/Radiowecker/issues">![GitHub issues](https://img.shields.io/github/issues/frankyhub/Radiowecker)![GitHub closed issues](https://img.shields.io/github/issues-closed/frankyhub/Radiowecker)|<a href="https://github.com/frankyhub/Radiowecker/discussions">![GitHub Discussions](https://img.shields.io/github/discussions/frankyhub/Radiowecker)|<a href="https://github.com/frankyhub/Radiowecker/releases">![GitHub release (with filter)](https://img.shields.io/github/v/release/frankyhub/Radiowecker)|
|![GitHub Created At](https://img.shields.io/github/created-at/frankyhub/Radiowecker)| <a href="https://github.com/frankyhub/Radiowecker/pulse" alt="Activity"><img src="https://img.shields.io/github/commit-activity/m/badges/shields" />| <a href="https://github.com/frankyhub/Radiowecker/graphs/traffic"><img alt="ViewCount" src="https://views.whatilearened.today/views/github/frankyhub/github-clone-count-badge.svg">  |<a href="https://github.com/frankyhub?tab=stars"> ![GitHub User's stars](https://img.shields.io/github/stars/frankyhub)|
</div>




Nach einer Idee und Vorlage von https://www.az-delivery.de/blogs/azdelivery-blog-fur-arduino-und-raspberry-pi/internet-radiowecker-mit-touchscreen.

# Radiowecker
Bedienung über 2,8" Touchscreen und WEB-Server, 3W Klasse D Amplifier



![Bild](pic/rw2.png) 



## Story
Das Repo beschreibt einen Radiowecker mit TFT-Display und WEB-Server. Zwei Weckzeiten können an beliebigen Wochentagen zugeordnet werden. Es ist auch ein Einschlaf-Timer vorhanden. Mit dem LDR kann man die Display-Helligkeit automatisch an die Raumhelligkeit anpassen. Über den Touchscreen sind Radio ein/aus, Einschlaftimer mit Einschlafzeit, Wecker ein/aus, Senderauswahl und Lautstärke einstellbar. Die Weckzeiten und die Stream-URLs der Radiostationen werden über ein Web-Interface konfiguriert.



![Bild](pic/TFT1.png) ![Bild](pic/TFT2.png)

## Inbetriebnahme

### Verdrahtung 

| TFT-Display | ESP32 | 
| -------- | -------- | 
|  VCC  |  3,3V  |
|  GND |   GDN |
| CS  | GPIO5  |
| RESET  | GPIO22   |
| DC | NC  |
| SDI  | GPIO23    |
| SCK  |  GPIO18  |
|  LED |  GPIO15  |
|  MISO | GPIO19   | 
| T-CLK  | GPIO18 |    
| T-CS  | GPIO14  | 
| T-DIN  | GPIO23  | 
| T-DO  | GPIO19  | 
| T-IRQ  | GPIO27  | 
|  --- |  --- | 


![Bild](pic/Schaltplan.png)

### ESP32 TFT 2.8" Shield

![Bild](pic/shield.png)

### Gehäuse

![Bild](pic/lbrn.png)



### Nach anlegen der Versorgungsspannung startet der Accesspoit. In den Einstellungen des Handys oder Tablets wird das WLAN "Radiowecker" ausgewählt 

![Bild](pic/notcon.png)

![Bild](pic/Apoint1.png)

### und über einen Browser die URL 192.168.4.1 eingegeben und der Neustart-Button betätigt.

![Bild](pic/Apoint2.png)

### Am Seriellen Monitor kann der Startvorgang beobachtet und die IP-Adresse des WEB-Servers abgelesen werden.

![Bild](pic/Smonitor1.png)

### Am Display wird beim Startvorgang die WLAN-Verbindung angezeigt.

![Bild](pic/TFT0.png)

### Nach dem Aufruf des WEB-Server sieht man die Einstellungen und passt diese an.

![Bild](pic/Einstellungen.png)

### Die Bedienung kann auch über das TFT-Display erfolgen.

![Bild](pic/TFT2.png)

![Bild](pic/TFT3.png)

## Bedienung

### Radio ein/aus
Das Radio wird ein- oder ausgeschaltet. Die Anzeige kehrt zur Zeitanzeige zurück. Wurde das Radio eingeschaltet, erscheint unter der Zeitanzeige der Radioblock mit dem Sendernamen.

### Einschlaftimer
Die Einschlafzeit wird gestartet. Falls das Radio nicht eingeschaltet ist, wird es eingeschaltet. Die Anzeige kehrt zur Zeitanzeige zurück. Wenn die eingestellte Einschlafzeit vorüber ist, wird das Radio automatisch ausgeschaltet.

### Wecker ein/aus
Die Wecker-Funktion wird ein- oder ausgeschaltet. Die Anzeige kehrt zur Zeitanzeige zurück. Wurde der Wecker eingeschaltet, erscheint ganz unten im Display der Wochentag und die Uhrzeit, wann der Wecker das nächste Mal ausgelöst wird. Wenn der angezeigte Wochentag und die Uhrzeit zutreffen, wird das Radio automatisch eingeschaltet.

### Sender speichern
Der ausgewählte Sender wird als aktiver Sender übernommen. Ist das Radio gerade eingeschaltet, so wechselt der Stream automatisch auf den neuen Sender. Die Anzeige kehrt zur Zeitanzeige zurück.

### Zurück
Die Anzeige kehrt zur Zeitanzeige zurück.


Erfolgt 10 Sekunden keine Aktivität, so kehrt die Anzeige automatisch zur Zeitanzeige zurück. Alle Einstellungsänderungen werden in den Präferenzen gespeichert. Die Bedienungsseite wird immer mit voller Helligkeit dargestellt.

![Bild](pic/TFT1.png)

## Konfiguration

### Über die URL http://radiowecker/ sollte die Konfigurationsseite abrufbar sein. 

![Bild](pic/OTA.png)

Im oberen Teil sieht man die WLAN-Zugangsdaten und den NTP-Server. Mit dem "Speichern-Button" werden Änderungen wirksam. Auch ein Neustart ist möglich. Als Nächstes folgen die Weckzeiten. Zwei Weckzeiten sind möglich. Für jede der Weckzeiten sind die Wochentage wählbar, an denen die Weckzeiten anzuwenden sind. Die Dropdown-Liste darunter enthält alle Sender der Senderliste. Auswählbare Sender haben vor dem Namen einen schwarzen Punkt. Im Formular darunter werden die Daten zur ausgewählten Station angezeigt und können geändert werden. Ist das Häkchen bei „Verwenden“ nicht gesetzt, ist die Station im Gerät nicht aktiv. Da manche URLs nicht funktionieren, sollte man eine neue URL erstmal testen. Ein Klicken auf den "Testen-Button" startet die Wiedergabe der URL am eingeschalteten Gerät. Sollte die Wiedergabe nicht funktionieren, wird wieder auf den aktuellen Sender zurückgeschaltet und eine Meldung angezeigt. Ist die Wiedergabe möglich, wird eine Box mit einem Knopf angezeigt. Klicken auf diesen Knopf schließt die Box und beendet den Test. Es wird wieder die aktuelle Station wiedergegeben. Im Eingabefeld „Position“ wird die Position der ausgewählten Station innerhalb der Senderliste angezeigt. Durch eine Änderung dieses Wertes, kann die Station auf die angegebene Position verschoben und mit dem Knopf „Ändern“ können die Änderungen für die ausgewählte Station dauerhaft geändert werden.

---

![Bild](pic/rw1.png) 

---

<div style="position:absolute; left:2cm; "> <ol class="breadcrumb" style="border-top: 2px solid black;border-bottom:2px solid black; height: 45px; width: 900px;"> <p align="center"><a href="#oben">nach oben</a></p></ol>
</div>  

---








