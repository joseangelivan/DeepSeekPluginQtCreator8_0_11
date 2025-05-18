# Definiciones y macros del plugin de Qt Creator
# Usar este archivo si no se puede incluir qtcreatorplugin.pri

# Define path to license file
isEmpty(IDE_LICENSE_FILE): IDE_LICENSE_FILE = LICENSE.GPL3-EXCEPT

# Definir la versión mínima de Qt Creator
QTCREATOR_VERSION = 8.0.1
QTCREATOR_COMPAT_VERSION = 8.0.1

# Definir destino de instalación
IDE_PLUGIN_PATH = $$IDE_BUILD_TREE/lib/qtcreator/plugins

# Definir variables de destino
target.path = $$IDE_PLUGIN_PATH
INSTALLS += target

# Definir macros comunes
DEFINES += DEEPSEEK_LIBRARY

# Configuración para instalación
plugin_data.files = $$IDE_LICENSE_FILE
plugin_data.path = $$IDE_DATA_PATH
INSTALLS += plugin_data
