
Al a�adir un proyecto nuevo recuerda a�adir la p�gina de propiedades ProyectosSDL.props al nuevo proyecto:
Men� VER -> administrador de propiedades -> Agregar hoja de propiedades existente -> ProyectosSDL.props > Guardar

Las librerias que se utilizan en esta soluci�n (en el directorio bin) son las librerias de los directorios lib\x86 de SDL-2.0.4 y SDL_image-2.0.1.
Si quieres usar las librerias de lib\x64 copialas de SDL-2.0.4 y SDL_image-2.0.1 al directorio bin de la soluci�n.
Abre el archivo ProyectosSDL.props y modifica la l�nea correspondiente a LibraryPath.

Si quieres a�adir una nueva libreria, copia su directorio en la soluci�n y los bin de la libreria en el directorio bin de la soluci�n.
Y a�ade los nuevos elementos al archivo ProyectosSDL.props en las lineas: IncludePath, LibraryPath y AdditionalDependencies.
Tambi�n puedes crear otras p�ginas de propiedades.