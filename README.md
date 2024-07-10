<a name="oben"></a>

# Radiowecker
Bedienung über 2,8" Touchscreen und WEB-Server, 3W Klasse D Amplifier



![Bild](pic/rw2.png) 



## Story
Das Repo beschreibt einen Radiowecker mit TFT-Display und WEB-Server. Zwei Weckzeiten an beliebigen Wochentagen könnenzugeordnet werden. Es ist auch ein Einschlaf-Timer vorhanden. Mit einem optionalen LDR könnte man die Display-Helligkeit automatisch an die Raumhelligkeit angepassen. Über den Touchscreen sind Radio ein/aus, Einschlaftimer mit Einschlafzeit, Wecker ein/aus, Senderauswahl und Lautstärke einstellbar. Die Weckzeiten und die Stream-URLs der Radiostationen werden über ein Web-Interface konfiguriert.



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
|  LED |  NC  |
|  MISO | GPIO19   | 
| T-CLK  | GPIO18 |    
| T-CS  | GPIO14  | 
| T-DIN  | GPIO23  | 
| T-DO  | GPIO19  | 
| T-IRQ  | GPIO27  | 
|  --- |  --- | 


![Bild](pic/Schaltplan.png)

### Gehäuse

![Bild](pic/lbrn.png)



### Nach anlegen der Versorgungsspannung startet der Accesspoit. In den Einstellungen des Handys oder Tablets wird das WLAN "Radiowecker" ausgewählt 

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

### Radio ei/aus
Das Radio wird ein- oder ausgeschaltet. Die Anzeige kehrt zur Zeitanzeige zurück. Wurde das Radio eingeschaltet, erscheint unter der Zeitanzeige der Radioblock mit dem Sendernamen und den Metadaten z.B. Name des geraden gespielten Liedes, wenn diese der Sender mit überträgt. Das ist leider nicht immer der Fall.

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

<div style="position:absolute; left:2cm; ">   
<ol class="breadcrumb" style="border-top: 2px solid black;border-bottom:2px solid black; height: 45px; width: 900px;"> <p align="center"><a href="#oben">nach oben</a></p></ol>
</div>  

---








