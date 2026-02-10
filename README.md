# Tama

Проект электронного устройства **Tama**, включающий:
- прошивку микроконтроллера (PlatformIO, Arduino)
- PC-клиент (Python + C# WinForms)
- взаимодействие по TCP/IP и через COM-порт

Проект используется для управления устройством и (опционально) голосового ввода.

---

## Используемые технологии

### Firmware
- PlatformIO
- Arduino framework
- Плата: **Arduino Mega 2560**
- Язык: C++
- Adfruit

### PC software
- Python 3
- `speech_recognition`
- TCP/IP (localhost)
- C# (.NET, WinForms)

---

## Прошивка (PlatformIO)

### Требования
- Visual Studio Code
- PlatformIO extension

### Конфигурация (`platformio.ini`)
```ini
[env:megaatmega2560]
platform = atmelavr
board = megaatmega2560
framework = arduino
```
### Сборка и загрузка

1. Открыть папку `firmware/Tama` в VS Code
2. PlatformIO автоматически активируется
3. Нажать **Build**
4. Подключить плату и нажать **Upload**
## PC-клиент

### Python-сервис

Запускается как отдельный процесс и:
- поднимает TCP-сервер
- обрабатывает команды
- (опционально) запускает распознавание речи
Запуск:
`python Client.py <COM_PORT>`
Пример:
`python Client.py COM3`

### Windows-приложение (C#)
Функции:
- запуск Python-сервиса
- подключение по TCP
- отправка команд (PING / EXIT)
- логирование

Шаги:
1. Открыть проект `WinApp` в Visual Studio
2. Собрать и запустить
3. Выбрать COM-порт
4. Нажать **Connect**
