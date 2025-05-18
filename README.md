# DeepSeek Plugin para Qt Creator 16.0.1

Este plugin integra las capacidades de DeepSeek AI en Qt Creator 16.0.1 (basado en Qt 6.8.0 o superior).

## Características

- Envía selecciones de código directamente a DeepSeek AI
- Configura ajustes de API
- Visualiza respuestas en el panel de salida

## Instalación

### Compilar desde el código fuente

1. Asegúrate de tener Qt Creator 16.0.1 instalado
2. Clona este repositorio
3. Configura las rutas en `DeepSeekPlugin.pro` para que apunten a tu instalación de Qt Creator
4. Compila el plugin usando qmake:
   ```
   cd DeepSeekPlugin
   qmake
   make
   ```
5. Copia el plugin compilado al directorio de plugins de Qt Creator:
   ```
   cp libDeepSeekPlugin.so /opt/qtcreator-16.0.1/lib/qtcreator/plugins/
   ```

### Configurar el Plugin

1. Abre Qt Creator
2. Ve a Herramientas > Opciones > DeepSeek
3. Introduce tu clave de API de DeepSeek
4. Configura otros ajustes según sea necesario

## Uso

1. Selecciona código en el editor
2. Haz clic derecho y selecciona "Preguntar a DeepSeek" o usa la opción de menú Herramientas > DeepSeek > Preguntar a DeepSeek
3. Ingresa tu consulta
4. Visualiza la respuesta en el panel de salida de DeepSeek

## Requisitos

- Qt Creator 16.0.1
- Qt 6.8.0 o superior
- Clave de API de DeepSeek

## Cambios para compatibilidad con Qt Creator 16.0.1

- Actualización de rutas para apuntar a la nueva instalación de Qt Creator
- Actualización de dependencias en el archivo JSON del plugin
- Mejora de compatibilidad con Qt 6.8.0
- Actualización del estándar de C++ a C++17
- Inclusión de core5compat para mantener compatibilidad con código existente

## Licencia

Este proyecto está licenciado bajo la Licencia MIT - consulta el archivo LICENSE para más detalles.
