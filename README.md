# STM8 na PlatformIO (Windows & Linux)

Tento návod popisuje, jak zprovoznit vývojové prostředí pro mikrokontrolery **STM8** pomocí **PlatformIO**.

---

## Windows

### 1. Instalace
- Stáhnout a nainstalovat **ST Visual Programmer (STVP)**.
- Ve **Visual Studio Code** nainstalovat rozšíření **PlatformIO IDE**.

### 2. Příprava projektu
- V PlatformIO vytvořit nový projekt.
- Překopírovat do projektu složky **src**, **include** a soubor **platformio.ini** do kořenové složky.

Struktura projektu:
```
projekt/
├── src/
├── include/
├── platformio.ini
```
### 3. Kompilace a upload
- Spustit **Build** (✓)
- Spustit **Upload** (→)

Po úspěšném uploadu začne LED blikat frekvencí 0,5 Hz.

### 4. Možná chyba
Pokud se objeví:
Systém nemůže nalézt uvedenou cestu

Zkontrolujte cestu ke STVP v `platformio.ini`:
"C:\Program Files (x86)\STMicroelectronics\st_toolset\stvp\STVP_CmdLine.exe"

---

## Linux

### 1. Instalace
Nainstalujte rozšíření PlatformIO ve VS Code.

### 2. Příprava projektu
- Překopírovat složky **src**, **include** a soubor **platformio.ini**.

### 3. Úprava platformio.ini
Zakomentovat upload sekci:
```
upload_protocol = custom
upload_flags =
-BoardName=ST-LINK
-ProgMode=SWIM
-Device=STM8S208RB
-Port=USB
-verif
-progress
-verbose
-FileProg=$SOURCE
upload_command = "C:\Program Files (x86)\STMicroelectronics\st_toolst\stvp\STVP_CmdLine.exe" $UPLOAD_FLAGS
```

---
