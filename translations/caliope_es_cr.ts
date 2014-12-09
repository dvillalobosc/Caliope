<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="es_CR" sourcelanguage="en">
<context>
    <name>Backup</name>
    <message>
        <location filename="../backup.cpp" line="105"/>
        <source>Backup</source>
        <translation>Respaldo</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="108"/>
        <source>Note that there are options that exclude others.</source>
        <translation>Note que hay opciones que excluyen a otras.</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="82"/>
        <source>Cannot backup this kind of database</source>
        <translation>No es posible respaladar este tipo de base de datos</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="109"/>
        <source>&amp;File:</source>
        <translation>&amp;Archivo:</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="110"/>
        <source>Create Backup</source>
        <translation>Crear Respaldo</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="179"/>
        <source>Backup done.</source>
        <translation>Respaldo realizado.</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="195"/>
        <source>Add a DROP DATABASE statement before each CREATE DATABASE statement</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="202"/>
        <source>Add a DROP TABLE statement before each CREATE TABLE statement</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="206"/>
        <source>Add a DROP TRIGGER statement before each CREATE TRIGGER statement</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="210"/>
        <source>Surround each table dump with LOCK TABLES and UNLOCK TABLES statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="214"/>
        <source>Backup all databases</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="219"/>
        <source>Adds to a table dump all SQL statements needed to create any tablespaces used by an NDB Cluster table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="223"/>
        <source>Allow creation of column names that are keywords</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="229"/>
        <source>Add comments to the dump file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="233"/>
        <source>Produce more compact output</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="239"/>
        <source>Use complete INSERT statements that include column names</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="243"/>
        <source>Include all MySQL-specific table options in CREATE TABLE statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="252"/>
        <source>Write INSERT DELAYED statements rather than INSERT statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="256"/>
        <source>On a master replication server, delete the binary logs after performing the dump operation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="260"/>
        <source>For each table, surround the INSERT statements with statements to disable and enable keys</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="264"/>
        <source>Include dump date as &apos;Dump completed on&apos; comment if --comments is given</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="268"/>
        <source>Dump events from the dumped databases</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="272"/>
        <source>Use multiple-row INSERT syntax that include several VALUES lists</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="283"/>
        <source>Flush the MySQL server log files before starting the dump</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="287"/>
        <source>Emit a FLUSH PRIVILEGES statement after dumping the mysql database</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="293"/>
        <source>Dump binary columns using hexadecimal notation (for example, &apos;abc&apos; becomes 0x616263)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="300"/>
        <source>Write INSERT IGNORE statements rather than INSERT statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="306"/>
        <source>Lock all tables across all databases</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="310"/>
        <source>Lock all tables before dumping them</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="319"/>
        <source>Enclose the INSERT statements for each dumped table within SET autocommit = 0 and COMMIT statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="323"/>
        <source>This option suppresses the CREATE DATABASE statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="327"/>
        <source>Do not write CREATE TABLE statements that re-create each dumped table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="331"/>
        <source>Do not dump table contents</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="335"/>
        <source>Same as --skip-set-charset</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="339"/>
        <source>Do not write any CREATE LOGFILE GROUP or CREATE TABLESPACE statements in output</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="343"/>
        <source>Shorthand for --add-drop-table --add-locks --create-options --disable-keys --extended-insert --lock-tables --quick --set-charset.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="347"/>
        <source>Dump each table&apos;s rows sorted by its primary key, or by its first unique index</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="353"/>
        <source>Retrieve rows for a table from the server a row at a time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="357"/>
        <source>Quote identifiers within backtick characters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="362"/>
        <source>Write REPLACE statements rather than INSERT statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="366"/>
        <source>Dump stored routines (procedures and functions) from the dumped databases</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="372"/>
        <source>This option issues a BEGIN SQL statement before dumping data from the server</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="376"/>
        <source>Do not add a DROP TABLE statement before each CREATE TABLE statement</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="381"/>
        <location filename="../backup.cpp" line="386"/>
        <source>Do not add comments to the dump file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="391"/>
        <source>Do not produce more compact output</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="396"/>
        <source>Do not disable keys</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="401"/>
        <source>Turn off extended-insert</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="406"/>
        <source>Turn off the options set by --opt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="411"/>
        <source>Do not retrieve rows for a table from the server a row at a time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="416"/>
        <source>Do not quote identifiers</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="421"/>
        <source>Suppress the SET NAMES statement</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="426"/>
        <source>Do not dump triggers</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="431"/>
        <source>Turn off tz-utc</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="447"/>
        <source>Dump triggers for each dumped table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="451"/>
        <source>Add SET TIME_ZONE=&apos;+00:00&apos; to the dump file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="455"/>
        <source>Verbose mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="462"/>
        <source>Produce XML output</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>BaseDiffFile</name>
    <message>
        <location filename="../basedifffile.cpp" line="41"/>
        <source>File without changes</source>
        <translation>Archivo sin cambios</translation>
    </message>
</context>
<context>
    <name>BaseTextEditor</name>
    <message>
        <location filename="../basetexteditor.cpp" line="393"/>
        <source>Indent</source>
        <translation>Indentar</translation>
    </message>
    <message>
        <location filename="../basetexteditor.cpp" line="395"/>
        <source>Unindent</source>
        <translation>Desindentar</translation>
    </message>
    <message>
        <location filename="../basetexteditor.cpp" line="397"/>
        <source>Insert licence template</source>
        <translation>Insertar plantilla de licencia</translation>
    </message>
    <message>
        <location filename="../basetexteditor.cpp" line="399"/>
        <source>Visualize spaces</source>
        <translation>Visualizar espacios</translation>
    </message>
</context>
<context>
    <name>Catalogs</name>
    <message>
        <location filename="../catalogs.cpp" line="249"/>
        <source>Catalogs</source>
        <translation>Catálogos</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="67"/>
        <location filename="../catalogs.cpp" line="98"/>
        <location filename="../catalogs.cpp" line="113"/>
        <location filename="../catalogs.cpp" line="130"/>
        <location filename="../catalogs.cpp" line="153"/>
        <location filename="../catalogs.cpp" line="180"/>
        <location filename="../catalogs.cpp" line="200"/>
        <source>Name</source>
        <translation>Nombre</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="68"/>
        <source>Engine</source>
        <translation>Motor</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="71"/>
        <source>Version</source>
        <translation>Versión</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="72"/>
        <source>Row format</source>
        <translation>Formato de la fila</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="73"/>
        <source>Rows</source>
        <translation>Filas</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="74"/>
        <source>Row length</source>
        <translation>Tamaño de la fila</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="75"/>
        <source>Data length</source>
        <translation>Tamaño de los datos</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="76"/>
        <source>Max data length</source>
        <translation>Tamaño máximo de los datos</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="77"/>
        <source>Index length</source>
        <translation>Tamaño de lo índices</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="78"/>
        <source>Data free</source>
        <translation>Datos libres</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="79"/>
        <source>Autoincrement</source>
        <translation>Autoincremental</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="80"/>
        <source>Creation time</source>
        <translation>Tiempo de creación</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="81"/>
        <source>Update time</source>
        <translation>Tiempo de actualización</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="82"/>
        <source>Check time</source>
        <translation>Tiempo de revisión</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="83"/>
        <location filename="../catalogs.cpp" line="104"/>
        <location filename="../catalogs.cpp" line="116"/>
        <location filename="../catalogs.cpp" line="140"/>
        <location filename="../catalogs.cpp" line="170"/>
        <location filename="../catalogs.cpp" line="190"/>
        <location filename="../catalogs.cpp" line="219"/>
        <source>Collation</source>
        <translation>Colación</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="86"/>
        <source>Checksum</source>
        <translation>Checksum</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="87"/>
        <source>Options</source>
        <translation>Opciones</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="88"/>
        <location filename="../catalogs.cpp" line="122"/>
        <location filename="../catalogs.cpp" line="145"/>
        <location filename="../catalogs.cpp" line="167"/>
        <location filename="../catalogs.cpp" line="216"/>
        <source>Comment</source>
        <translation>Comentario</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="95"/>
        <source>Tables</source>
        <translation>Tablas</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="99"/>
        <source>Updatable</source>
        <translation>Actualizable</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="100"/>
        <location filename="../catalogs.cpp" line="168"/>
        <location filename="../catalogs.cpp" line="188"/>
        <location filename="../catalogs.cpp" line="201"/>
        <source>Definer</source>
        <translation>Definidor</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="101"/>
        <source>Security</source>
        <translation>Seguridad</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="102"/>
        <source>Check</source>
        <translation>Revisar</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="103"/>
        <location filename="../catalogs.cpp" line="139"/>
        <location filename="../catalogs.cpp" line="169"/>
        <location filename="../catalogs.cpp" line="189"/>
        <location filename="../catalogs.cpp" line="218"/>
        <source>Charset</source>
        <translation>Juego de caracteres</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="110"/>
        <source>Views</source>
        <translation>Vistas</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="114"/>
        <location filename="../catalogs.cpp" line="131"/>
        <source>Position</source>
        <translation>Posición</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="115"/>
        <source>Column</source>
        <translation>Columna</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="117"/>
        <source>Cardinality</source>
        <translation>Cardinalidad</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="118"/>
        <source>Subpart</source>
        <translation>Subparte</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="119"/>
        <source>Packed</source>
        <translation>Empacado</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="120"/>
        <source>Null</source>
        <translation>Null</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="121"/>
        <location filename="../catalogs.cpp" line="141"/>
        <location filename="../catalogs.cpp" line="154"/>
        <location filename="../catalogs.cpp" line="204"/>
        <source>Type</source>
        <translation>Tipo</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="127"/>
        <source>Indexes on: </source>
        <translation>Indices en:</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="132"/>
        <source>Default</source>
        <translation>Predeterminado</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="133"/>
        <source>Nullable</source>
        <translation>Anulable</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="134"/>
        <source>Datatype</source>
        <translation>Tipo de dato</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="135"/>
        <source>Character max length</source>
        <translation>Largo máximo de los caracteres</translation>
    </message>
    <message>
        <source>Character octect length</source>
        <translation type="obsolete">Longitud octal del caracter</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="136"/>
        <source>Character octet length</source>
        <translation>Longitud octeto de caracteres</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="137"/>
        <source>Numeric precision</source>
        <translation>Presición numérica</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="138"/>
        <source>Numeric scale</source>
        <translation>Escala numerica</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="142"/>
        <source>Key</source>
        <translation>Llave</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="143"/>
        <source>Extra</source>
        <translation>Extra</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="144"/>
        <source>Privileges</source>
        <translation>Privilegios</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="150"/>
        <source>Fields on: </source>
        <translation>Campos en:</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="155"/>
        <source>Returns</source>
        <translation>Retorna</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="156"/>
        <location filename="../catalogs.cpp" line="203"/>
        <source>Body</source>
        <translation>Cuerpo</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="157"/>
        <source>External name</source>
        <translation>Nombre externo</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="158"/>
        <source>External language</source>
        <translation>Lenguaje externo</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="159"/>
        <source>Parameter style</source>
        <translation>Estilo de los parámetros</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="160"/>
        <source>Is deterministic</source>
        <translation>Es determinista</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="161"/>
        <source>SQL data access</source>
        <translation>Acceso a datos SQL</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="162"/>
        <source>SQL path</source>
        <translation>Ruta SQL</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="163"/>
        <source>Security type</source>
        <translation>Tipo de seguridad</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="164"/>
        <location filename="../catalogs.cpp" line="186"/>
        <location filename="../catalogs.cpp" line="213"/>
        <source>Created</source>
        <translation>Creado</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="165"/>
        <location filename="../catalogs.cpp" line="214"/>
        <source>Last altered</source>
        <translation>Última alteración</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="166"/>
        <location filename="../catalogs.cpp" line="187"/>
        <location filename="../catalogs.cpp" line="208"/>
        <source>SQL mode</source>
        <translation>Modo SQL</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="171"/>
        <location filename="../catalogs.cpp" line="191"/>
        <location filename="../catalogs.cpp" line="220"/>
        <source>Database collation</source>
        <translation>Colación de la base de datos</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="177"/>
        <source>Routines</source>
        <translation>Rutinas</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="181"/>
        <source>Event manipulation</source>
        <translation>Manipulación de eventos</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="182"/>
        <source>Action order</source>
        <translation>Orden de la acción</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="183"/>
        <source>Action condition</source>
        <translation>Condición de la acción</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="184"/>
        <source>Acction orientation</source>
        <translation>Orientación de la acción</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="185"/>
        <source>Action timing</source>
        <translation>Sincronización de la acción</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="197"/>
        <source>Triggers</source>
        <translation>Disparadores</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="202"/>
        <source>Time zone</source>
        <translation>Zona de tiempo</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="205"/>
        <source>Execute at</source>
        <translation>Ejecutado en</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="206"/>
        <source>Internal value</source>
        <translation>Valor interno</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="207"/>
        <source>Internal field</source>
        <translation>Campo interno</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="209"/>
        <source>Starts</source>
        <translation>Inicia</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="210"/>
        <source>Ends</source>
        <translation>Finaliza</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="211"/>
        <source>Status</source>
        <translation>Estado</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="212"/>
        <source>On completion</source>
        <translation>Al finalizar</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="215"/>
        <source>Last executed</source>
        <translation>Última ejecución</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="217"/>
        <source>Originator</source>
        <translation>Originador</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="226"/>
        <source>Events</source>
        <translation>Eventos</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="274"/>
        <source>The column %1 cannot be modified.</source>
        <translation>La columna %1 no puede ser modificada.</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="278"/>
        <source>Changes applied.</source>
        <translation>Cambios aplicados.</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="281"/>
        <source>Tables in Read-Only mode, no changes will be applied.</source>
        <translation>Las tablas están en modo Solo-Lectura, los cambios no se aplicarán.</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="292"/>
        <source>Catalogs in %1</source>
        <translation>Catálogos en %1</translation>
    </message>
    <message>
        <source>Refresh</source>
        <translation type="obsolete">Refrescar</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="343"/>
        <source>Routine deletion</source>
        <translation>Borrado de rutina</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="344"/>
        <source>Do you really want to delete the routine?&lt;BR /&gt;</source>
        <translation>¿Realmente desea borrar la rutina?&lt;BR /&gt;</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="417"/>
        <source>Delete a database</source>
        <translation>Borrar base de datos</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="418"/>
        <source>Select a database to delete:</source>
        <translation>Seleccione una base de datos para borrar:</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="448"/>
        <source>Rows to be inserted</source>
        <translation>Filas a ser insertadas</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="449"/>
        <location filename="../catalogs.cpp" line="470"/>
        <source>Inserting records...</source>
        <translation>Insertando filas...</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="472"/>
        <source>Records inserted.</source>
        <translation>Registros insertados.</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="481"/>
        <source>New table</source>
        <translation>Nueva tabla</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="484"/>
        <source>New view</source>
        <translation>Nueva vista</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="487"/>
        <source>New index</source>
        <translation>Nuevo índice</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="490"/>
        <source>New field</source>
        <translation>Nuevo campo</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="493"/>
        <source>New routine</source>
        <translation>Nueva rutina</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="496"/>
        <source>New trigger</source>
        <translation>Nuevo trigger</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="499"/>
        <source>New event</source>
        <translation>Nuevo evento</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="583"/>
        <source>Indexes on: %1</source>
        <translation>Indices en: %1</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="585"/>
        <source>Fields on: %1</source>
        <translation>Campos en: %1</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="587"/>
        <source>Triggers on: %1</source>
        <translation>Disparadores en: %1</translation>
    </message>
</context>
<context>
    <name>CommitDialog</name>
    <message>
        <location filename="../commitdialog.cpp" line="39"/>
        <source>Commit changes for </source>
        <translation>Cometar cambios para </translation>
    </message>
    <message>
        <location filename="../commitdialog.cpp" line="64"/>
        <source>&amp;User:</source>
        <translation>&amp;Usuario:</translation>
    </message>
    <message>
        <location filename="../commitdialog.cpp" line="65"/>
        <source>&amp;Password:</source>
        <translation>&amp;Contraseña:</translation>
    </message>
    <message>
        <location filename="../commitdialog.cpp" line="60"/>
        <source>Commit log</source>
        <translation>Log de cambios</translation>
    </message>
    <message>
        <location filename="../commitdialog.cpp" line="61"/>
        <source>Diff file</source>
        <translation>Archivo Diff</translation>
    </message>
</context>
<context>
    <name>ConnectDialog</name>
    <message>
        <location filename="../connectdialog.cpp" line="45"/>
        <source>Connect to a Database Server</source>
        <translation>Conectarse a un Servidor de Base de Datos</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="56"/>
        <source>Sort connection list by used times</source>
        <translation>Ordenar la lista de conexiones por las veces usadas</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="124"/>
        <source>&amp;Connection Name:</source>
        <translation>&amp;Nombre de la Conexión:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="126"/>
        <source>Connection &amp;Type:</source>
        <translation>&amp;Tipo de Conexión:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="127"/>
        <source>&amp;Server:</source>
        <translation>&amp;Servidor:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="128"/>
        <source>&amp;Port:</source>
        <translation>&amp;Puerto:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="129"/>
        <source>&amp;User:</source>
        <translation>&amp;Usuario:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="130"/>
        <source>&amp;Password:</source>
        <translation>&amp;Contraseña:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="131"/>
        <source>Database:</source>
        <translation>Base de Datos:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="132"/>
        <source>Collation:</source>
        <translation>Cotejo:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="107"/>
        <source>Store passwords</source>
        <translation>Almacenar contraseñas</translation>
    </message>
</context>
<context>
    <name>DBMS</name>
    <message>
        <source>MariaDB Version</source>
        <translation type="obsolete">Versión de MariaDB</translation>
    </message>
    <message>
        <source>Your version of MariaDB seems to be less than 5.1</source>
        <translation type="obsolete">Su versión de MariaDB parece ser mejor a 5.1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="238"/>
        <location filename="../dbms.cpp" line="239"/>
        <source>Connection is not opened.</source>
        <translation>La conexión no está abierta.</translation>
    </message>
    <message>
        <source>SQL Error</source>
        <translation type="obsolete">Error SQL</translation>
    </message>
    <message>
        <source>Rows in set</source>
        <translation type="obsolete">Filas en el resultado</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="441"/>
        <location filename="../dbms.cpp" line="455"/>
        <source>Rows in set: %1</source>
        <translation>Filas en el resultado: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="463"/>
        <location filename="../dbms.cpp" line="552"/>
        <source>Undefined Database driver.</source>
        <translation>Controlador de Base de datos indefinido.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="568"/>
        <location filename="../dbms.cpp" line="575"/>
        <source>Error:</source>
        <translation>Error:</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="582"/>
        <source>No error code provided.</source>
        <translation>No hay código de error proporcionado.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="693"/>
        <source>Select a file</source>
        <translation>Seleccione un archivo</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="702"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="706"/>
        <source>Data exported to %1</source>
        <translation>Datos exportados a %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="59"/>
        <source>Error</source>
        <translation>Error</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="56"/>
        <source>Count</source>
        <translation>Contador</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="56"/>
        <location filename="../dbms.cpp" line="1370"/>
        <source>Query</source>
        <translation>Consulta</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="56"/>
        <source>Error message</source>
        <translation>Mensaje de error</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="68"/>
        <source>Cannot open database</source>
        <translation>No es posible abrir la base de datos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="68"/>
        <source>Unable to establish a database connection.</source>
        <translation>Imposible establecer una conexión con la base de datos.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="157"/>
        <source>MySQL Version</source>
        <translation>Versión de MySQL</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="157"/>
        <source>Your version of MySQL seems to be less than 5.1.</source>
        <translation>Su versión de MySQL parece ser mejor a 5.1.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="180"/>
        <source>Stage: %1 of %2 &apos;%3&apos;. %4% of stage done.
Total progess: %5.</source>
        <translation>Etapa: %1 de %2 &apos;%3&apos;. %4% de la etapa realizado.\nProgreso total: %5.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="197"/>
        <source>%1 seconds</source>
        <translation>%1 segundos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="199"/>
        <source>%1 minutes</source>
        <translation>%1 minutos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="201"/>
        <source>%1 hours</source>
        <translation>%1 horas</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="208"/>
        <source>Application closed</source>
        <translation>Aplicación cerrada</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="410"/>
        <location filename="../dbms.cpp" line="415"/>
        <source>Rows in set: %1. Elapsed time: %2.</source>
        <translation>Filas en el resultado: %1. Tiempo transcurrido: %2.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="425"/>
        <location filename="../dbms.cpp" line="431"/>
        <source>Rows in set: %1. Elapsed time: %2 seconds.</source>
        <translation>Filas en el resultado: %1. Tiempo transcurrido: %2.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="905"/>
        <source>Could not execute statement. </source>
        <translation>No se puede ejecutar la sentencia. </translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1351"/>
        <source>Application started</source>
        <translation>Aplicación iniciada</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1366"/>
        <source>Line Number</source>
        <translation>Número de línea</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1367"/>
        <source>Session Id</source>
        <translation>Id de Sesión</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1368"/>
        <source>Date</source>
        <translation>Fecha</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1369"/>
        <source>Connection</source>
        <translation>Conexión</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1540"/>
        <source>Restarting connection</source>
        <translation>Reiniciando conexión</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1540"/>
        <source>This acction will restart your database connection</source>
        <translation>Esta acción reiniciará su conexión a base de datos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1682"/>
        <location filename="../dbms.cpp" line="1689"/>
        <source>Could not change character set to: %1</source>
        <translation>No se puede cambiar el juego de caracteres a: %1</translation>
    </message>
</context>
<context>
    <name>DBarChartWidget</name>
    <message>
        <location filename="../serverInformation.cpp" line="675"/>
        <source>Total connections in the last 60 seconds</source>
        <translation>Total de conexiones en los últimos 60 segundos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="676"/>
        <source>Kb sent by second</source>
        <translation>Kb enviados por segundo</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="677"/>
        <source>Executed queries in the last 60 seconds</source>
        <translation>Consultas ejecutadas en los últimos 60 segundos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="729"/>
        <source>Current: %1</source>
        <translation>Actual %1</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="730"/>
        <source>Max: %1</source>
        <translation>Máximo: %1</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="731"/>
        <source>Min: %1</source>
        <translation>Mínimo: %1</translation>
    </message>
</context>
<context>
    <name>DPieChartWidget</name>
    <message>
        <source>Total: %1 MBs.</source>
        <translation type="obsolete">Total: %1 MBs.</translation>
    </message>
    <message>
        <source>Total: %1.</source>
        <translation type="obsolete">Total: %1.</translation>
    </message>
    <message>
        <location filename="../dpiechartwidget.cpp" line="83"/>
        <source>Total: %1 %2.</source>
        <translation>Total: %1 %2.</translation>
    </message>
</context>
<context>
    <name>DQueryLog</name>
    <message>
        <location filename="../dquerylog.cpp" line="92"/>
        <source>File size: %1 Mb. File path: %2.</source>
        <translation>Tamaño del archivo %1 Mb. Ruta del archivo: %2.</translation>
    </message>
    <message>
        <location filename="../dquerylog.cpp" line="126"/>
        <source>Query Log</source>
        <translation>Log de Sentencias</translation>
    </message>
    <message>
        <location filename="../dquerylog.cpp" line="129"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../dquerylog.cpp" line="130"/>
        <source>Refresh</source>
        <translation>Refrescar</translation>
    </message>
    <message>
        <location filename="../dquerylog.cpp" line="131"/>
        <source>Clear log</source>
        <translation>Limpiar el log</translation>
    </message>
    <message>
        <location filename="../dquerylog.cpp" line="132"/>
        <source>Three characters at least</source>
        <translation>Tres caracteres como mínimo</translation>
    </message>
    <message>
        <location filename="../dquerylog.cpp" line="133"/>
        <source>Filter by query:</source>
        <translation>Filtrar por consulta:</translation>
    </message>
</context>
<context>
    <name>DReportViewer</name>
    <message>
        <location filename="../dreportviewer.cpp" line="28"/>
        <source>Report:</source>
        <translation>Reporte:</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="124"/>
        <source>Plain text</source>
        <translation>Texto plano</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="126"/>
        <source>Pie chart</source>
        <translation>Gráfico circular</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="131"/>
        <source>&amp;Report Name:</source>
        <translation>&amp;Nombre el Reporte:</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="132"/>
        <source>&amp;Unit:</source>
        <translation>&amp;Unidad:</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="133"/>
        <source>&amp;Type:</source>
        <translation>&amp;Tipo:</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="189"/>
        <source>Export to PDF</source>
        <translation>Exportar a Pdf</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="190"/>
        <source>Refresh</source>
        <translation>Refrescar</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="191"/>
        <source>Export to Image</source>
        <translation>Exportar a Imagen</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="192"/>
        <source>Export to TXT</source>
        <translation>Exportar a TXT</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="200"/>
        <source>Save to Pdf</source>
        <translation>Guardar en Pdf</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="200"/>
        <source>Pdf &amp; Ps files (*.pdf *.ps)</source>
        <translation>Archivos Pdf &amp; Ps (*.pdf *.ps)</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="207"/>
        <location filename="../dreportviewer.cpp" line="224"/>
        <location filename="../dreportviewer.cpp" line="251"/>
        <source>File saved at: %1</source>
        <translation>Archivo guardado en: %1</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="218"/>
        <source>Save to Image</source>
        <translation>Guardar en Imagen</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="218"/>
        <source>Image files (%1)</source>
        <translation>Archivos de imagen (%1)</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="243"/>
        <source>Save file</source>
        <translation>Guardar archivo</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="243"/>
        <source>Text files (%1)</source>
        <translation>Archivos de Texto (%1)</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="247"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
</context>
<context>
    <name>DTableView</name>
    <message>
        <location filename="../dtableview.cpp" line="79"/>
        <location filename="../dtableview.cpp" line="101"/>
        <source>Loading records...</source>
        <translatorcomment>Registros cargados.</translatorcomment>
        <translation>Cargando registros...</translation>
    </message>
    <message>
        <location filename="../dtableview.cpp" line="111"/>
        <source>Records loaded.</source>
        <translation>Registros cargados.</translation>
    </message>
</context>
<context>
    <name>DWebView</name>
    <message>
        <source>URL to load</source>
        <translation type="obsolete">URL a cargar</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="63"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="105"/>
        <source>Show page source</source>
        <translation>Mostrar el fuente de la página</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="106"/>
        <source>Open in external browser</source>
        <translation>Abrir en explorador externo</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="111"/>
        <location filename="../dwebview.cpp" line="136"/>
        <source>Loading page...</source>
        <translation>Cargando página...</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="117"/>
        <source>Page loaded.</source>
        <translation>Página cargada.</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="119"/>
        <source>Could not load page.</source>
        <translation>No se puede cargar la página.</translation>
    </message>
</context>
<context>
    <name>Database</name>
    <message>
        <location filename="../dbms.cpp" line="1801"/>
        <source>Database: %1</source>
        <translation>Base de Datos: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1802"/>
        <source>Total of tables: %1</source>
        <translation>Total de tablas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1803"/>
        <source>Total of views: %1</source>
        <translation>Total de vistas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1804"/>
        <source>Total of triggers: %1</source>
        <translation>Total de disparadores: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1805"/>
        <source>Total of rutines: %1</source>
        <translation>Total de rutinas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1806"/>
        <source>Total of events: %1</source>
        <translation>Total de eventos: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1807"/>
        <source>Tables size: %1</source>
        <translation>Tamaño total de las tablas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1808"/>
        <source>Idexes: %1</source>
        <translation>Tamaño total de los índices: %1</translation>
    </message>
</context>
<context>
    <name>DatabaseComparision</name>
    <message>
        <location filename="../databasecomparision.cpp" line="88"/>
        <source>Database Comparision</source>
        <translation>Comparación de Bases de Datos</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="91"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="92"/>
        <source>Primary compare</source>
        <translation>Comparación primaria</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="94"/>
        <source>Secondary compare</source>
        <translation>Comparación secundaria</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="102"/>
        <source>Original database server: %1</source>
        <translation>Servidor de bases de datos original: %1</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="144"/>
        <source>Cannot connect to the server</source>
        <translation>No es posible conectarse al servidor</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="148"/>
        <source>Secondary database server: %1</source>
        <translation>Servidor de bases de datos secundario: %1</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="151"/>
        <source>Connected successfully to: %1</source>
        <translation>Conectado satisfactoriamente a: %1</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="184"/>
        <location filename="../databasecomparision.cpp" line="188"/>
        <location filename="../databasecomparision.cpp" line="192"/>
        <location filename="../databasecomparision.cpp" line="201"/>
        <location filename="../databasecomparision.cpp" line="205"/>
        <source>Server</source>
        <translation>Servidor</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="184"/>
        <location filename="../databasecomparision.cpp" line="188"/>
        <location filename="../databasecomparision.cpp" line="192"/>
        <location filename="../databasecomparision.cpp" line="201"/>
        <location filename="../databasecomparision.cpp" line="205"/>
        <source>Database</source>
        <translation>Base de Datos</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="184"/>
        <location filename="../databasecomparision.cpp" line="188"/>
        <location filename="../databasecomparision.cpp" line="192"/>
        <location filename="../databasecomparision.cpp" line="201"/>
        <location filename="../databasecomparision.cpp" line="205"/>
        <source>Table</source>
        <translation>Tabla</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="184"/>
        <location filename="../databasecomparision.cpp" line="188"/>
        <location filename="../databasecomparision.cpp" line="192"/>
        <location filename="../databasecomparision.cpp" line="201"/>
        <location filename="../databasecomparision.cpp" line="205"/>
        <source>Data length</source>
        <translation>Tamaño de los datos</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="184"/>
        <location filename="../databasecomparision.cpp" line="188"/>
        <location filename="../databasecomparision.cpp" line="192"/>
        <location filename="../databasecomparision.cpp" line="201"/>
        <location filename="../databasecomparision.cpp" line="205"/>
        <source>Row count</source>
        <translation>Conteo de filas</translation>
    </message>
</context>
<context>
    <name>DiffFile</name>
    <message>
        <location filename="../difffile.cpp" line="52"/>
        <source>Diff file</source>
        <translation>Archivo Diff</translation>
    </message>
</context>
<context>
    <name>Editor</name>
    <message>
        <source>&amp;File</source>
        <translation type="obsolete">&amp;Archivo</translation>
    </message>
    <message>
        <source>SQL Query %1</source>
        <translation type="obsolete">Consulta SQL %1</translation>
    </message>
    <message>
        <source>PHP Script %1</source>
        <translation type="obsolete">Script PHP %1</translation>
    </message>
    <message>
        <source>CSS Script %1</source>
        <translation type="obsolete">Script CSS %1</translation>
    </message>
    <message>
        <source>HTML Script %1</source>
        <translation type="obsolete">Script HTML %1</translation>
    </message>
    <message>
        <source>JavaScript Script %1</source>
        <translation type="obsolete">Script JavaScript %1</translation>
    </message>
    <message>
        <source>Text File %1</source>
        <translation type="obsolete">Archivo de Texto %1</translation>
    </message>
    <message>
        <source>&amp;View</source>
        <translation type="obsolete">&amp;Ver</translation>
    </message>
</context>
<context>
    <name>FileAssociations</name>
    <message>
        <location filename="../fileassociations.cpp" line="56"/>
        <source>SQL files:</source>
        <translation>Archivos SQL:</translation>
    </message>
    <message>
        <location filename="../fileassociations.cpp" line="58"/>
        <source>PHP files:</source>
        <translation>Archivos PHP:</translation>
    </message>
    <message>
        <location filename="../fileassociations.cpp" line="60"/>
        <source>CSS files:</source>
        <translation>Archivos CSS:</translation>
    </message>
    <message>
        <location filename="../fileassociations.cpp" line="62"/>
        <source>HTML files:</source>
        <translation>Archivos HTML:</translation>
    </message>
    <message>
        <location filename="../fileassociations.cpp" line="64"/>
        <source>JavaScript files:</source>
        <translation>Archivos JavaScript:</translation>
    </message>
</context>
<context>
    <name>FileSelector</name>
    <message>
        <location filename="../fileselector.cpp" line="70"/>
        <source>SQL files (*.sql)</source>
        <translation>Archivos SQL (*.sql)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="73"/>
        <source>Text files (*.txt)</source>
        <translation>Archivos de Texto (*.txt)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="76"/>
        <source>Project files (*.pro)</source>
        <translation>Archivos de Proyecto (*.pro)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="79"/>
        <source>Bin files (*)</source>
        <translation>Archivos Bin (*)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="82"/>
        <source>Image files (*.png *.jpg *.bmp)</source>
        <translation>Archivo de imagen (*.png *.jpg *.bmp)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="112"/>
        <location filename="../fileselector.cpp" line="114"/>
        <source>Open a file</source>
        <translation>Abrir un archivo</translation>
    </message>
</context>
<context>
    <name>FindReplace</name>
    <message>
        <location filename="../findreplace.cpp" line="43"/>
        <source>Find/Replace</source>
        <translation>Encontrar/Remplazar</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="56"/>
        <source>Find next</source>
        <translation>Encontrar siguiente</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="61"/>
        <source>Find previous</source>
        <translation>Econtrar previo</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="68"/>
        <source>Replace</source>
        <translation>Remplazar</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="73"/>
        <source>Replace all</source>
        <translation>Remplazar todo</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="77"/>
        <source>Case sensitive</source>
        <translation>Sensible a mayúsculas y minúsculas</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="81"/>
        <source>Hole word</source>
        <translation>Palabra completa</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="85"/>
        <source>Regular Expression</source>
        <translation>Expresión regular</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="89"/>
        <source>Highlight all</source>
        <translation>Resaltar todo</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="132"/>
        <source>Reached the end of the document.</source>
        <translation>Llegó al final del documento.</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="139"/>
        <source>Reached the begining of the document.</source>
        <translation>Llegó al inicio del documento.</translation>
    </message>
</context>
<context>
    <name>LicenseTemplate</name>
    <message>
        <location filename="../licensetemplate.cpp" line="51"/>
        <source>From a file</source>
        <translation>Desde un archivo</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../mainwindow.cpp" line="113"/>
        <source>Cannot read file %1:
%2.</source>
        <translation>No es posible leer el archivo %1:
%2.</translation>
    </message>
    <message>
        <source>Options</source>
        <translation type="obsolete">Opciones</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="174"/>
        <location filename="../mainwindow.cpp" line="1200"/>
        <location filename="../mainwindow.cpp" line="1363"/>
        <location filename="../mainwindow.cpp" line="1753"/>
        <source>Server Information</source>
        <translation>Información del Servidor</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="176"/>
        <location filename="../mainwindow.cpp" line="1366"/>
        <source>User Administration</source>
        <translation>Administración de Usuarios</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="178"/>
        <location filename="../mainwindow.cpp" line="1369"/>
        <location filename="../mainwindow.cpp" line="1661"/>
        <source>Backup</source>
        <translation>Respaldo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="180"/>
        <location filename="../mainwindow.cpp" line="1649"/>
        <source>Restore</source>
        <translation>Restaurar</translation>
    </message>
    <message>
        <source>Schemas</source>
        <translation type="obsolete">Esquemas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="182"/>
        <location filename="../mainwindow.cpp" line="269"/>
        <location filename="../mainwindow.cpp" line="1375"/>
        <location filename="../mainwindow.cpp" line="1765"/>
        <source>Catalogs</source>
        <translation>Catálogos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="184"/>
        <location filename="../mainwindow.cpp" line="1381"/>
        <location filename="../mainwindow.cpp" line="1841"/>
        <source>Table Maintenance</source>
        <translation>Mantenimiento de Tablas</translation>
    </message>
    <message>
        <source>Metadata</source>
        <translation type="obsolete">Metadata</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="186"/>
        <location filename="../mainwindow.cpp" line="1715"/>
        <source>Process List</source>
        <translation>Lista de Procesos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="282"/>
        <source>In God we trust</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="283"/>
        <source>In a world without walls and fences, who needs windows and gates?</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="284"/>
        <source>Wellcome!!! Have a nice day.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="285"/>
        <source>MariaDB is great!!!</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="286"/>
        <source>Qt is great!!!</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="287"/>
        <source>Open space has more fresh air than closed Windows</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="288"/>
        <source>Microsoft gives you &quot;Windows&quot;, Linux a &quot;home&quot;!</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="194"/>
        <location filename="../mainwindow.cpp" line="1378"/>
        <source>Query</source>
        <translation>Consulta</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1387"/>
        <source>PHP Script</source>
        <translation>Script PHP</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1357"/>
        <location filename="../mainwindow.cpp" line="2229"/>
        <source>About CalÃ­ope</source>
        <translation>Acerca de Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1372"/>
        <source>Restore Backup</source>
        <translation>Restaurar Respaldo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1384"/>
        <source>SQL Script</source>
        <translation>Script SQL</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="192"/>
        <source>SQL Query</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="196"/>
        <source>PHP</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1525"/>
        <source>Refresh</source>
        <translation>Refrescar</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1528"/>
        <source>Read only</source>
        <translation>Solo lectura</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1531"/>
        <source>Create Database</source>
        <translation>Crear Base de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1534"/>
        <source>Delete Database</source>
        <translation>Borrar Base de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1522"/>
        <location filename="../mainwindow.cpp" line="1540"/>
        <source>Select recent file...</source>
        <translation>Seleccionar un archivo reciente...</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="198"/>
        <location filename="../mainwindow.cpp" line="930"/>
        <source>Database Comparision</source>
        <translation>Comparación de Bases de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="855"/>
        <location filename="../mainwindow.cpp" line="1492"/>
        <source>PostgreSQL On-Line Help</source>
        <translation>Ayuda en Línea de PostgreSQL</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="865"/>
        <location filename="../mainwindow.cpp" line="1495"/>
        <source>MariaDB On-Line Help</source>
        <translation>Ayuda en Línea de MariaDB</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="889"/>
        <source>External Web Page</source>
        <translation>Página Web Externa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="900"/>
        <source>Visited sites</source>
        <translation>Sitios visitados</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="918"/>
        <source>The slave has been reset.</source>
        <translation>El esclavo ha sido reestablecido.</translation>
    </message>
    <message>
        <source>Database Comaparision</source>
        <translation type="obsolete">Comparación de Bases de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="997"/>
        <source>Migrating data</source>
        <translation>Migrando datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="997"/>
        <source>Abort</source>
        <translation>Abortar</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1011"/>
        <location filename="../mainwindow.cpp" line="1297"/>
        <location filename="../mainwindow.cpp" line="1304"/>
        <location filename="../mainwindow.cpp" line="1314"/>
        <source>Database migration</source>
        <translation>Migración de bases de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1011"/>
        <source>Database migration is only aviable for MariaDB and MySQL.</source>
        <translation>La migración de bases de datos solo está dispobible para MariaDB y MySQL.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1018"/>
        <source>Table count: %1</source>
        <translation>Conteo de tablas: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="188"/>
        <location filename="../mainwindow.cpp" line="1090"/>
        <source>Query Log</source>
        <translation>Log de Sentencias</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1116"/>
        <location filename="../mainwindow.cpp" line="1515"/>
        <source>Database information</source>
        <translation>Información de la base de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1127"/>
        <source>Save to Image</source>
        <translation>Guardar en Imagen</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1127"/>
        <source>Image files (%1)</source>
        <translation>Archivos de imagen (%1)</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1133"/>
        <source>File saved at: %1</source>
        <translation>Archivo guardado en: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1209"/>
        <location filename="../mainwindow.cpp" line="1561"/>
        <source>HDD Usage Graphics</source>
        <translation>Gráfico de uso de HDD</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1218"/>
        <location filename="../mainwindow.cpp" line="1564"/>
        <source>Executed Queries</source>
        <translation>Consultas Ejecutadas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1227"/>
        <location filename="../mainwindow.cpp" line="1567"/>
        <source>Data Sent/Received</source>
        <translation>Datos Enviados/Recibidos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1236"/>
        <location filename="../mainwindow.cpp" line="1248"/>
        <source>Custom reports</source>
        <translation>Reportes personalizados</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1279"/>
        <location filename="../mainwindow.cpp" line="1573"/>
        <source>Slow Queries</source>
        <translation>Consultas lentas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1297"/>
        <source>Migration done.</source>
        <translation>Migración realizada.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1345"/>
        <source>The database server has been shutdown.</source>
        <translation>El servidor de base de datos ha sido apagado.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1355"/>
        <source>Shows the About dialog for Qt.</source>
        <translation>Muestra el cuadro de diálogo de Acerda de Qt.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1358"/>
        <source>Shows the About dialog for CalÃ­ope.</source>
        <translation>Muestra el cuadro de diálogo de Acerda de Calíope.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1360"/>
        <source>Connect to Server...</source>
        <translation>Conectarse al Servidor...</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1361"/>
        <source>Connect to a Database Server.</source>
        <translation>Conectarse a un Servidor de Base de Datos.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1390"/>
        <source>CalÃ­ope</source>
        <translation>Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1393"/>
        <source>MySQL Help</source>
        <translation>Ayuda de MySQL</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1396"/>
        <source>View query log</source>
        <translation>Ver el log de consultas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1399"/>
        <location filename="../mainwindow.cpp" line="1706"/>
        <location filename="../mainwindow.cpp" line="1727"/>
        <source>MySQL On-Line Help</source>
        <translation>Ayuda en Línea de MySQL</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1402"/>
        <location filename="../mainwindow.cpp" line="1698"/>
        <source>PHP On-Line Help</source>
        <translation>Ayuda en Línea de PHP</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1405"/>
        <location filename="../mainwindow.cpp" line="1626"/>
        <source>Preferences</source>
        <translation>Preferencias</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1408"/>
        <source>Processes</source>
        <translation>Procesos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1410"/>
        <source>&amp;File Toolbar</source>
        <translation>Barra de Herramientas de &amp;Archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1416"/>
        <source>&amp;Close connection</source>
        <translation>&amp;Cerrar conexión</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1417"/>
        <source>Close current database connection</source>
        <translation>Cerrar conexión de base de datos actual</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1419"/>
        <source>Cascade windows</source>
        <translation>Ventanas en cascada</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1422"/>
        <source>Next window</source>
        <translation>Próxima ventana</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1425"/>
        <source>Previous window</source>
        <translation>Ventana previa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1428"/>
        <source>Close current window</source>
        <translation>Cerrar ventana actual</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1431"/>
        <source>Close all windows</source>
        <translation>Cerrar todas las ventanas</translation>
    </message>
    <message>
        <source>Sort by title</source>
        <translation type="obsolete">Ordenar por título</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1437"/>
        <source>Shutdown Database Server</source>
        <translation>Apagar el Servidor de Base de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1440"/>
        <source>CSS Editor</source>
        <translation>Editor CSS</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1443"/>
        <source>HTML Editor</source>
        <translation>Editor HTML</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1446"/>
        <source>JavaScript Editor</source>
        <translation>Editor JavaScript</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1449"/>
        <source>Web site</source>
        <translation>Sitio web</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1452"/>
        <source>Full screen</source>
        <translation>Pantalla completa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1455"/>
        <source>Objects diagram</source>
        <translation>Diagrama de Objetos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1458"/>
        <source>Open file</source>
        <translation>Abrir archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1462"/>
        <source>Text Editor</source>
        <translation>Editor de Texto</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1465"/>
        <source>Stop Slave</source>
        <translation>Detener Esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1471"/>
        <source>Start Slave</source>
        <translation>Iniciar Esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1474"/>
        <source>Restart Slave</source>
        <translation>Reiniciar Esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1477"/>
        <source>Replication Information</source>
        <translation>Información de la Replicación</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1552"/>
        <source>Take a snapshot</source>
        <translation>Tomar una instantánea</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1164"/>
        <location filename="../mainwindow.cpp" line="1555"/>
        <source>CalÃ­ope source documentation</source>
        <translation>Documentación fuente de Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2206"/>
        <source>Cannot load the translation.</source>
        <translation>No es posible cargar la traducción.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="828"/>
        <location filename="../mainwindow.cpp" line="1486"/>
        <source>Time Difference</source>
        <translation>Diferencia de Tiempo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1489"/>
        <source>Show the Slow Log</source>
        <translation>Mostrar el Slow Log</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="636"/>
        <source>Objects Diagram</source>
        <translation>Diagrama de Objetos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="703"/>
        <source>Open a file</source>
        <translation>Abrir un archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="793"/>
        <source>The replication slave has been stoped.</source>
        <translation>El esclavo de replicación ha sido detenido.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="799"/>
        <source>The replication slave has been started.</source>
        <translation>El esclavo de replicación ha sido iniciado.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="805"/>
        <source>The replication slave has been rebooted.</source>
        <translation>El esclavo de replicación ha sido reiniciado.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="817"/>
        <source>Privileges flushed.</source>
        <translation>Privilegios refrescados.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="823"/>
        <source>Logs purged.</source>
        <translation>Logs purgados.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="829"/>
        <source>Seconds of difference: %1</source>
        <translation>Segundos de diferencia: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="837"/>
        <source>Select a date</source>
        <translation>Seleccione una fecha</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="924"/>
        <source>Logs flushed.</source>
        <translation>Registros limpiados.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1351"/>
        <source>&amp;Quit</source>
        <translation>&amp;Salir</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1352"/>
        <source>Exits the application.</source>
        <translation>Sale de laplicación.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1354"/>
        <source>About &amp;Qt</source>
        <translation>Acerca de &amp;Qt</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1434"/>
        <source>Tile windows</source>
        <translation>Ventanas en mosaico</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1468"/>
        <source>Reset Slave</source>
        <translation>Restablecer esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1514"/>
        <source>Recent connections</source>
        <translation>Conexiones recientes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1516"/>
        <source>Reports</source>
        <translation>Reportes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1537"/>
        <source>Populate table</source>
        <translation>Poblar tabla</translation>
    </message>
    <message>
        <source>Cannot open database</source>
        <translation type="obsolete">Ni es posible abrir la base de datos</translation>
    </message>
    <message>
        <source>Unable to establish a database connection.</source>
        <translation type="obsolete">Imposible establecer una conexión con la base de datos.</translation>
    </message>
    <message>
        <source>Application started</source>
        <translation type="obsolete">Aplicación iniciada</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1637"/>
        <source>Users</source>
        <translation>Usuarios</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1690"/>
        <source>External Web page</source>
        <translation>Página Web externa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1082"/>
        <location filename="../mainwindow.cpp" line="1815"/>
        <source>Connected successfully to: %1</source>
        <translation>Conectado satisfactoriamente a: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1853"/>
        <source>Result</source>
        <translation>Resultado</translation>
    </message>
    <message>
        <source>Databases</source>
        <translation type="obsolete">Bases de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1499"/>
        <location filename="../mainwindow.cpp" line="1519"/>
        <source>Editors</source>
        <translation>Editores</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1520"/>
        <source>Project files</source>
        <translation>Archivos de proyecto</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1501"/>
        <source>Open external web page</source>
        <translation>Abrir una página web externa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1502"/>
        <location filename="../mainwindow.cpp" line="2042"/>
        <source>&amp;File</source>
        <translation>&amp;Archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1503"/>
        <source>Recent files</source>
        <translation>Archivos recientes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1504"/>
        <source>&amp;Projects</source>
        <translation>&amp;Proyectos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1505"/>
        <source>&amp;Conecction</source>
        <translation>&amp;Conexión</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1506"/>
        <source>Change character set</source>
        <translation>Cambiar conjunto de caracteres</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1507"/>
        <source>Change database</source>
        <translation>Cambiar base de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1508"/>
        <location filename="../mainwindow.cpp" line="2120"/>
        <source>Replication</source>
        <translation>Replicación</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1509"/>
        <source>Maintenance</source>
        <translation>Mantenimiento</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1510"/>
        <source>&amp;View</source>
        <translation>&amp;Ver</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1511"/>
        <source>&amp;Languaje</source>
        <translation>&amp;Idioma</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1512"/>
        <source>&amp;Window</source>
        <translation>&amp;Ventana</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1513"/>
        <source>&amp;Help</source>
        <translation>&amp;Ayuda</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1543"/>
        <source>Clear recent files</source>
        <translation>Limpiar archivos recientes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1546"/>
        <source>Database comparation</source>
        <translation>Comparación de Bases de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1549"/>
        <source>Migrate database</source>
        <translation>Migrar base de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1080"/>
        <location filename="../mainwindow.cpp" line="1811"/>
        <source>Cannot connect to the server</source>
        <translation>No es posible conectarse al servidor</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1558"/>
        <source>Server information</source>
        <translation>Información del Servidor</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1570"/>
        <source>Create a custom report</source>
        <translation>Crear un reporte personalizado</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1576"/>
        <source>Tell us your comments</source>
        <translation>Dígamos sus comentarios</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2117"/>
        <source>General</source>
        <translation>General</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2123"/>
        <source>Logs</source>
        <translation>Registros</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2256"/>
        <source>Windows</source>
        <translation>Ventanas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2267"/>
        <source>Windows options</source>
        <translation>Opciones de ventanas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2326"/>
        <source>Character set changed to: %1</source>
        <translation>Conjunto de caracteres cambiado a: %1</translation>
    </message>
</context>
<context>
    <name>Metadata</name>
    <message>
        <source>Metadata</source>
        <translation type="obsolete">Metadata</translation>
    </message>
</context>
<context>
    <name>MySQLHelp</name>
    <message>
        <location filename="../mysqlhelp.cpp" line="81"/>
        <source>MySQL Help</source>
        <translation>Ayuda de MySQL</translation>
    </message>
    <message>
        <location filename="../mysqlhelp.cpp" line="84"/>
        <source>Topics</source>
        <translation>Tópicos</translation>
    </message>
    <message>
        <location filename="../mysqlhelp.cpp" line="85"/>
        <source>Enter a Keyword</source>
        <translation>Ingrese una palabra clave</translation>
    </message>
    <message>
        <location filename="../mysqlhelp.cpp" line="121"/>
        <source>Syntax:</source>
        <translation>Sintaxis:</translation>
    </message>
    <message>
        <location filename="../mysqlhelp.cpp" line="122"/>
        <source>Example:</source>
        <translation>Ejemplo:</translation>
    </message>
    <message>
        <location filename="../mysqlhelp.cpp" line="124"/>
        <source>URL:</source>
        <translation>URL:</translation>
    </message>
</context>
<context>
    <name>NetworkSettings</name>
    <message>
        <location filename="../networksettings.cpp" line="68"/>
        <source>Use proxy for Internet connections.</source>
        <translation>Usar proxy para las conexiones de Internet.</translation>
    </message>
    <message>
        <location filename="../networksettings.cpp" line="70"/>
        <source>Proxy address:</source>
        <translation>Dirección del proxy:</translation>
    </message>
    <message>
        <location filename="../networksettings.cpp" line="72"/>
        <source>Port:</source>
        <translation>Puerto:</translation>
    </message>
    <message>
        <location filename="../networksettings.cpp" line="73"/>
        <location filename="../networksettings.cpp" line="76"/>
        <source>Leave it blank if is not needed</source>
        <translation>Déjelo en blanco si no se necesita</translation>
    </message>
    <message>
        <location filename="../networksettings.cpp" line="75"/>
        <location filename="../networksettings.cpp" line="78"/>
        <source>Username:</source>
        <translation>Nombre de usuario:</translation>
    </message>
    <message>
        <location filename="../networksettings.cpp" line="80"/>
        <source>Password:</source>
        <translation>Contraseña:</translation>
    </message>
    <message>
        <location filename="../networksettings.cpp" line="81"/>
        <source>Apply changes</source>
        <translation>Aplicar cambios</translation>
    </message>
    <message>
        <location filename="../networksettings.cpp" line="82"/>
        <source>Settings will be applied when application restarts.</source>
        <translation>Los ajustes se aplicarán cuando se reinicie la aplicación.</translation>
    </message>
</context>
<context>
    <name>NewDatabase</name>
    <message>
        <location filename="../newdatabase.cpp" line="34"/>
        <source>New database</source>
        <translation>Nueva base de Datos</translation>
    </message>
    <message>
        <location filename="../newdatabase.cpp" line="43"/>
        <source>Name:</source>
        <translation>Nombre:</translation>
    </message>
    <message>
        <location filename="../newdatabase.cpp" line="44"/>
        <source>Collation</source>
        <translation>Colación</translation>
    </message>
</context>
<context>
    <name>ObjectSelection</name>
    <message>
        <source>Databases</source>
        <translation type="obsolete">Bases de Datos</translation>
    </message>
</context>
<context>
    <name>ObjectsDiagram</name>
    <message>
        <location filename="../objectsdiagram.cpp" line="55"/>
        <source>Objects Diagram</source>
        <translation>Diagrama de Objetos</translation>
    </message>
</context>
<context>
    <name>Preferences</name>
    <message>
        <location filename="../preferences.cpp" line="209"/>
        <source>Preferences</source>
        <translation>Preferencias</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="213"/>
        <source>Select a style:</source>
        <translation>Seleccione un estilo:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="214"/>
        <source>Remember opened windows</source>
        <translation>Recordar ventanas abiertas</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="215"/>
        <source>Open last file used in the modules</source>
        <translation>Abrir el último archivo usado en los módulos</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="216"/>
        <source>Save Queries before execution?</source>
        <translation>¿Guardar Consultas antes de la ejecución?</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="217"/>
        <source>Appilcation Style</source>
        <translation>Estilo de la Aplicación</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="93"/>
        <source>General</source>
        <translation>General</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="85"/>
        <source>Change default background image</source>
        <translation>Cambiar la imagen de fondo predeterminada</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="157"/>
        <source>Count</source>
        <translation>Contador</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="158"/>
        <source>Collation</source>
        <translation>Colación</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="186"/>
        <source>Application Theme</source>
        <translation>Tema de la Aplicación</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="218"/>
        <source>Spaces</source>
        <translation>Espacios</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="220"/>
        <source>Tab size:</source>
        <translation>Tamaño del tabulador:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="221"/>
        <source>Enable automatic indentation.</source>
        <translation>Habilitar indentación automática.</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="222"/>
        <source>Clean white spaces at the end of the line.</source>
        <translation>Limpiar espacios en blanco al final de la línea.</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="223"/>
        <source>Save a backup copy before save a file.</source>
        <translation>Guardar una copia de seguridad antes de guardar el archivo.</translation>
    </message>
    <message>
        <source>Show Tabs and Spaces.</source>
        <translation type="obsolete">Mostar Tabulaciones y Espacios.</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="120"/>
        <source>Text Editor</source>
        <translation>Editor de Texto</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="124"/>
        <source>License Template</source>
        <translation>Plantilla de Licencia</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="128"/>
        <source>Network Settings</source>
        <translation>Configuración de la red</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="151"/>
        <source>Name</source>
        <translation>Nombre</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="154"/>
        <source>Server</source>
        <translation>Servidor</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="155"/>
        <source>Port</source>
        <translation>Puerto</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="153"/>
        <source>User</source>
        <translation>Usuario</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="159"/>
        <source>Password</source>
        <translation>Contraseña</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="156"/>
        <source>Database</source>
        <translation>Base de Datos</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="152"/>
        <source>Type</source>
        <translation>Tipo</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="168"/>
        <source>Connections Settings</source>
        <translation>Configuración de las Conexiones</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="172"/>
        <source>File Associations</source>
        <translation>Asociaciones de Archivo</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="225"/>
        <source>Enable query log</source>
        <translation>Habilitar el log de sentencias</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="229"/>
        <source>PHP CLI Command:</source>
        <translation>Comando PHP CLI:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="182"/>
        <source>PHP</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>ProcessList</name>
    <message>
        <location filename="../processlist.cpp" line="136"/>
        <source>Process List</source>
        <translation>Lista de Procesos</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="50"/>
        <location filename="../processlist.cpp" line="60"/>
        <source>Id</source>
        <translation>Id</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="51"/>
        <location filename="../processlist.cpp" line="61"/>
        <source>User</source>
        <translation>Usuario</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="52"/>
        <location filename="../processlist.cpp" line="62"/>
        <source>Host</source>
        <translation>Huésped</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="53"/>
        <location filename="../processlist.cpp" line="63"/>
        <source>Database</source>
        <translation>Base de Datos</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="54"/>
        <location filename="../processlist.cpp" line="64"/>
        <source>Command</source>
        <translation>Comando</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="55"/>
        <location filename="../processlist.cpp" line="65"/>
        <source>Time</source>
        <translation>Tiempo</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="56"/>
        <location filename="../processlist.cpp" line="66"/>
        <source>State</source>
        <translation>Estado</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="57"/>
        <location filename="../processlist.cpp" line="67"/>
        <source>Info</source>
        <translation>Info</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="68"/>
        <source>Milliseconds</source>
        <translation>Milisegundos</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="69"/>
        <source>Stage</source>
        <translation>Etapa</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="70"/>
        <source>Max Stage</source>
        <translation>Máxima Etapa</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="71"/>
        <source>Progress</source>
        <translation>Progreso</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="72"/>
        <source>Memory</source>
        <translation>Memoria</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="73"/>
        <source>Examined Rows</source>
        <translation>Filas Examinadas</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="74"/>
        <source>Query Id</source>
        <translation>Consulta Id</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="77"/>
        <source>DatId</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="78"/>
        <source>DatName</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="79"/>
        <source>ProcPid</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="80"/>
        <source>UseName</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="81"/>
        <source>Current Query</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="82"/>
        <source>Waiting</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="83"/>
        <source>Xact Start</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="84"/>
        <source>Query Start</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="85"/>
        <source>Backend Start</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="86"/>
        <source>Client Addr</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="87"/>
        <source>Client Port</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="139"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="140"/>
        <source>Stop refreshing</source>
        <translation>Detener refrescado</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="141"/>
        <source>Kill thread</source>
        <translation>Matar hilo</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="142"/>
        <source>Kills the given thread.</source>
        <translation>Mata el proceso dado.</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="143"/>
        <source>Kill idle threads</source>
        <translation>Matar hilos inactivos</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="144"/>
        <source>Kills thread exeding 30 seconds inactive.</source>
        <translation>Mata los hilos que exceden 30 inactivos.</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="189"/>
        <source>Kill thread: %1</source>
        <translation>Matar hilo: %1</translation>
    </message>
</context>
<context>
    <name>ProjectFindReplace</name>
    <message>
        <location filename="../projectfindreplace.cpp" line="45"/>
        <location filename="../projectfindreplace.cpp" line="48"/>
        <source>Select a Project first.</source>
        <translation>Primero seleccione un Proyecto.</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="47"/>
        <source>Project Error</source>
        <translation>Error en el Proyecto</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="112"/>
        <source>Find &amp; Replace</source>
        <translation>Búsqueda &amp; Reemplazo</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="116"/>
        <source>Text to find:</source>
        <translation>Texto a buscar:</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="118"/>
        <source>Text to replace:</source>
        <translation>Texto a reemplazar:</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="119"/>
        <source>Find</source>
        <translation>Buscar</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="120"/>
        <source>Case sensitive</source>
        <translation>Sensible a mayúsculas y minúsculas</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="121"/>
        <source>Whole words</source>
        <translation>Palabra completa</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="122"/>
        <source>Regular expression</source>
        <translation>Expresión regular</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="123"/>
        <source>Results</source>
        <translation>Resultados</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="124"/>
        <source>Replace</source>
        <translation>Remplazar</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="192"/>
        <source>Do you really want to apply the changes?</source>
        <translation>¿Realmente desea aplicar los cambios?</translation>
    </message>
</context>
<context>
    <name>Projects</name>
    <message>
        <location filename="../projects.cpp" line="336"/>
        <source>New Project...</source>
        <translation>Nuevo Proyecto...</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="338"/>
        <source>Open Project...</source>
        <translation>Abrir Proyecto...</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="340"/>
        <source>Recent files</source>
        <translation>Archivos recientes</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="342"/>
        <source>Clear recent files</source>
        <translation>Limpiar archivos recientes</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="344"/>
        <source>Close current project</source>
        <translation>Cerrar el proyecto actual</translation>
    </message>
    <message>
        <source>Find in current project</source>
        <translation type="obsolete">Encontrar en el proyecto actual</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="346"/>
        <source>Find in project</source>
        <translation>Encontrar en el proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="348"/>
        <source>Project files</source>
        <translation>Archivos de proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="349"/>
        <source>Subversion</source>
        <translation>Subversion</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="350"/>
        <source>Add new file to project</source>
        <translation>Agregar un archivo nuevo al proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="352"/>
        <source>Add existing file to project</source>
        <translation>Agregar un archivo existente al proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="114"/>
        <source>Clean</source>
        <translation>Limpiar</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="145"/>
        <source>No projet</source>
        <translation>Sin proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="362"/>
        <source>Open a project</source>
        <translation>Abrir proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="362"/>
        <source>Project files (*.pro)</source>
        <translation>Archivos de Proyecto (*.pro)</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="381"/>
        <source>New project...</source>
        <translation>Nuevo proyecto...</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="390"/>
        <source>&amp;Name:</source>
        <translation>&amp;Nombre:</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="391"/>
        <source>Destination:</source>
        <translation>Destino:</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="393"/>
        <source>Poject information</source>
        <translation>Información del proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="397"/>
        <source>Load files</source>
        <translation>Cargar archivos</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="409"/>
        <source>Poject files</source>
        <translation>Archivos de proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="417"/>
        <source>Create new Project</source>
        <translation>Crear un nuevo Proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="430"/>
        <location filename="../projects.cpp" line="519"/>
        <location filename="../projects.cpp" line="525"/>
        <source>Info saved.</source>
        <translation>Información guardada.</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="486"/>
        <source>Select files</source>
        <translation>Seleccionar archivos</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="518"/>
        <source>File name</source>
        <translation>Nombre del archivo</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="524"/>
        <source>Select a file</source>
        <translation>Seleccione un archivo</translation>
    </message>
</context>
<context>
    <name>QBarChartWidget</name>
    <message>
        <source>Total connections in the last 60 seconds</source>
        <translation type="obsolete">Total de conexiones en los últimos 60 segundos</translation>
    </message>
    <message>
        <source>Kb sent by second</source>
        <translation type="obsolete">Kb enviados por segundo</translation>
    </message>
    <message>
        <source>Executed queries in the last 60 seconds</source>
        <translation type="obsolete">Consultas ejecutadas en los últimos 60 segundos</translation>
    </message>
    <message>
        <source>Current: %1</source>
        <translation type="obsolete">Actual %1</translation>
    </message>
    <message>
        <source>Max: %1</source>
        <translation type="obsolete">Máximo: %1</translation>
    </message>
    <message>
        <source>Min: %1</source>
        <translation type="obsolete">Mínimo: %1</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../basedifffile.cpp" line="41"/>
        <source>Version control</source>
        <translation>Control de versiones</translation>
    </message>
    <message>
        <source>Cannot write file %1:
%2.</source>
        <translation type="obsolete">No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../objectsdiagram.cpp" line="79"/>
        <source>Table: %1</source>
        <translation>Tabla: %1</translation>
    </message>
</context>
<context>
    <name>Restore</name>
    <message>
        <location filename="../restore.cpp" line="105"/>
        <source>Restore</source>
        <translation>Restaurar</translation>
    </message>
    <message>
        <location filename="../restore.cpp" line="108"/>
        <source>Unfortunately read backup files is a very complex process. Especially when finding objects names. Therefore we recommend that only use backup files created with this application. But restore an entire file should work without any problem.</source>
        <translation>Desafortunadamente leer los archivos de copia de respaldo es un proceso muy complejo. Especialmente por la búsqueda de nombres de objetos. Por lo tanto le recomendamos que utilice únicamente los archivos de copia de respaldo creados con esta aplicación. Pero restaurar un archivo completo debería funcionar sin ningún problema.</translation>
    </message>
    <message>
        <location filename="../restore.cpp" line="112"/>
        <source>&amp;File:</source>
        <translation>&amp;Archivo:</translation>
    </message>
    <message>
        <location filename="../restore.cpp" line="113"/>
        <source>File information</source>
        <translation>Información del archivo</translation>
    </message>
    <message>
        <location filename="../restore.cpp" line="115"/>
        <source>File:</source>
        <translation>Archivo:</translation>
    </message>
    <message>
        <location filename="../restore.cpp" line="117"/>
        <source>Total schemas:</source>
        <translation>Total de esquemas:</translation>
    </message>
    <message>
        <location filename="../restore.cpp" line="119"/>
        <source>Total tables:</source>
        <translation>Toral de tablas:</translation>
    </message>
    <message>
        <location filename="../restore.cpp" line="121"/>
        <source>Total data length:</source>
        <translation>Tamaño total de los datos:</translation>
    </message>
    <message>
        <location filename="../restore.cpp" line="122"/>
        <source>Options</source>
        <translation>Opciones</translation>
    </message>
    <message>
        <location filename="../restore.cpp" line="123"/>
        <source>Ignore errors</source>
        <translation>Ignorar errores</translation>
    </message>
    <message>
        <location filename="../restore.cpp" line="124"/>
        <source>Restore the entire file</source>
        <translation>Restaurar el archivo completo</translation>
    </message>
    <message>
        <location filename="../restore.cpp" line="125"/>
        <source>Object selection</source>
        <translation>Selección de objetos</translation>
    </message>
</context>
<context>
    <name>Result</name>
    <message>
        <location filename="../result.cpp" line="89"/>
        <source>Result</source>
        <translation>Resultado</translation>
    </message>
    <message>
        <source>Result toolbar</source>
        <translation type="obsolete">Barra de herramientas de resultado</translation>
    </message>
    <message>
        <location filename="../result.cpp" line="91"/>
        <source>Refresh</source>
        <translation>Refrescar</translation>
    </message>
    <message>
        <location filename="../result.cpp" line="92"/>
        <source>Apply changes</source>
        <translation>Aplicar cambios</translation>
    </message>
    <message>
        <location filename="../result.cpp" line="93"/>
        <source>Discard changes</source>
        <translation>Descartar los cambios</translation>
    </message>
    <message>
        <location filename="../result.cpp" line="94"/>
        <location filename="../result.cpp" line="250"/>
        <source>Delete line: %1</source>
        <translation>Borrar línea: %1</translation>
    </message>
    <message>
        <location filename="../result.cpp" line="95"/>
        <source>History</source>
        <translation>Historial</translation>
    </message>
    <message>
        <location filename="../result.cpp" line="96"/>
        <source>Add a row</source>
        <translation>Agregar una fila</translation>
    </message>
    <message>
        <location filename="../result.cpp" line="190"/>
        <source>Result for: %1.%2</source>
        <translation>Resultado para %1.%2</translation>
    </message>
    <message>
        <location filename="../result.cpp" line="193"/>
        <source>Database or table does not exist.</source>
        <translation>Base de datos o la tabla no existen.</translation>
    </message>
</context>
<context>
    <name>SQLQuery</name>
    <message>
        <location filename="../sqlquery.cpp" line="154"/>
        <source>Query %1</source>
        <translation>Consulta: %1</translation>
    </message>
    <message>
        <source>Query toolbar</source>
        <translation type="obsolete">Barra de herramientas de consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="157"/>
        <source>Run</source>
        <translation>Correr</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="158"/>
        <source>Runs a query</source>
        <translation>Correr como consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="159"/>
        <source>Export</source>
        <translation>Exportar</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="160"/>
        <source>Export query output</source>
        <translation>Exportar salida de la consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="161"/>
        <source>History</source>
        <translation>Historial</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="163"/>
        <source>Show New Lines</source>
        <translation>Mostrar Nuevas Líneas</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="165"/>
        <source>Start SQL Player</source>
        <translation>Iniciar el SQL Player</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="167"/>
        <source>Split query</source>
        <translation>Dividir consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="169"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="171"/>
        <source>Start/Pause execution</source>
        <translation>Iniciar/Pausar ejecución</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="183"/>
        <source>Concatenate query output</source>
        <translation>Concatenar la salida de la consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="185"/>
        <source>Export table data for INSERT</source>
        <translation>Exportar los datos de la tabla para INSERT</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="187"/>
        <source>Explain SELECT</source>
        <translation>Explicar SELECT</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="189"/>
        <source>Explain INSERT</source>
        <translation>Explicar INSERT</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="191"/>
        <source>Safe statements</source>
        <translation>Consultas seguras</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="193"/>
        <source>Show statements with error</source>
        <translation>Mostrar sentencias con error</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="195"/>
        <source>Explain UPDATE</source>
        <translation>Explicar UPDATE</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="197"/>
        <source>Repeate execution</source>
        <translation>Repetir ejecución</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="199"/>
        <source>Word wrap on result</source>
        <translation>Ajuste de línea en el resultado</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="200"/>
        <source>Log statements</source>
        <translation>Loguear sentencias</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="202"/>
        <source>TRIM columns in table</source>
        <translation>Recortar las columnas en la tabla</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="204"/>
        <source>Check tables status</source>
        <translation>Revisar el estado de las tablas</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="439"/>
        <source>Could not execute statement on safe mode.</source>
        <translation>No es posible ejecutar esta consulta en modo seguro.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="440"/>
        <source>Safe mode</source>
        <translation>Modo seguro</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="488"/>
        <source>Save to Pdf</source>
        <translation>Guardar en Pdf</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="488"/>
        <source>Pdf &amp; Ps files (*.pdf *.ps)</source>
        <translation>Archivos Pdf &amp; Ps (*.pdf *.ps)</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="495"/>
        <source>File saved at: %1</source>
        <translation>Archivo guardado en: %1</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="574"/>
        <source>Select a file</source>
        <translation>Seleccione un archivo</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="577"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="585"/>
        <source>Incorrect use of the EXPORT DATA FOR INSERT Option. Example: EXPORT DATA FOR INSERT `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Exportar los datos de la tabla para INSERT. Ejemplo: EXPORT DATA FOR INSERT `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="604"/>
        <source>Incorrect use of the EXPLAIN SELECT Option. Example: SELECT * FROM `columns_pri`, it only works for the current database, the asterisk must be selected.</source>
        <translation>Uso incorrecto de la Opción Explicar SELECT. Ejemplo: SELECT * FROM `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="622"/>
        <source>Incorrect use of the EXPLAIN INSERT Option. Example: INSERT INTO `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Explicar INSERT. Ejemplo: INSERT INTO `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="750"/>
        <source>Incorrect use of the TRIM columns Option. Example: TRIM COLUMNS IN `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Recortar las columnas. Ejemplo: TRIM COLUMNS IN `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <source>Bad use of the EXPORT DATA FOR INSERT option.</source>
        <translation type="obsolete">Mal uso de la opción: Exportar los datos de la tabla para INSERT.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="635"/>
        <source>seconds</source>
        <translation>segundos</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="639"/>
        <location filename="../sqlquery.cpp" line="644"/>
        <source>minutes</source>
        <translation>minutos</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="646"/>
        <source>Elapsed: %1 %2. Remaining: %3 %4.
Total of queries: %5, remaining: %6.
Queries per second: %7.</source>
        <translation>Transcurrido: %1 %2. Restante: %3 %4.\nTotal de sentencias: %5, restantes: %6.\nConsultas por segundo: %7.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="702"/>
        <source>Incorrect use of the EXPLAIN UPDATE Option. Example: UPDATE `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Explicar UPDATE. Ejemplo: UPDATE `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="711"/>
        <source>Repeat time in seconds</source>
        <translation>Tiempo de repetición en segundos</translation>
    </message>
    <message>
        <source>Elapsed: %1 %2. Remaining: %3 %4.
Total of queries: %5, remaining: %6.</source>
        <translation type="obsolete">Transcurrido: %1 %2. Restante: %3 %4.\nTotal de sentencias: %5, restantes: %6.</translation>
    </message>
    <message>
        <source>Elapsed: %1 %2. Remaining: %3 %4.</source>
        <translation type="obsolete">Transcurrido: %1 %2. Restante: %3 %4.</translation>
    </message>
    <message>
        <source>Run query</source>
        <translation type="obsolete">Ejecutar consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="173"/>
        <source>Stop execution</source>
        <translation>Detener ejecución</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="175"/>
        <source>Run previous query</source>
        <translation>Ejecutar consulta previa</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="177"/>
        <source>Run next query</source>
        <translation>Ejecutar próxima consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="179"/>
        <source>Run first query</source>
        <translation>Ejecutar la primera consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="181"/>
        <source>Run last query</source>
        <translation>Ejecutar la última consulta</translation>
    </message>
    <message>
        <source>Empty query</source>
        <translation type="obsolete">Consulta vacía</translation>
    </message>
</context>
<context>
    <name>SVNLog</name>
    <message>
        <location filename="../svnlog.cpp" line="50"/>
        <source>Log file</source>
        <translation>Archivo de log</translation>
    </message>
</context>
<context>
    <name>Schemas</name>
    <message>
        <source>Schemas</source>
        <translation type="obsolete">Esquemas</translation>
    </message>
    <message>
        <source>Database</source>
        <translation type="obsolete">Base de Datos</translation>
    </message>
    <message>
        <source>Name</source>
        <translation type="obsolete">Nombre</translation>
    </message>
    <message>
        <source>Engine</source>
        <translation type="obsolete">Motor</translation>
    </message>
    <message>
        <source>Rows</source>
        <translation type="obsolete">Filas</translation>
    </message>
    <message>
        <source>Size</source>
        <translation type="obsolete">Tamaño</translation>
    </message>
    <message>
        <source>Update Time</source>
        <translation type="obsolete">Feha de Actualización</translation>
    </message>
    <message>
        <source>Schemas in %1</source>
        <translation type="obsolete">Esquemas en %1</translation>
    </message>
    <message>
        <source>Refresh</source>
        <translation type="obsolete">Refrescar</translation>
    </message>
</context>
<context>
    <name>ServerInformation</name>
    <message>
        <location filename="../serverInformation.cpp" line="311"/>
        <source>Server Information</source>
        <translation>Información del Servidor</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="314"/>
        <source>User:</source>
        <translation>Usuario:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="316"/>
        <source>Host:</source>
        <translation>Huésped:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="318"/>
        <source>Socket:</source>
        <translation>Socket:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="320"/>
        <source>Port:</source>
        <translation>Puerto:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="322"/>
        <source>Version:</source>
        <translation>Versión:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="324"/>
        <source>Connection id:</source>
        <translation>Id de la conexión:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="326"/>
        <source>Server status:</source>
        <translation>Estado del servidor:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="327"/>
        <source>Connection</source>
        <translation>Conexión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="328"/>
        <source>Status</source>
        <translation>Estado</translation>
    </message>
    <message>
        <source>Refresh</source>
        <translation type="obsolete">Refrescar</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="332"/>
        <location filename="../serverInformation.cpp" line="339"/>
        <source>Replication Status</source>
        <translation>Estado del Replicador</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="333"/>
        <location filename="../serverInformation.cpp" line="342"/>
        <location filename="../serverInformation.cpp" line="347"/>
        <location filename="../serverInformation.cpp" line="350"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="334"/>
        <source>Skip 0</source>
        <translation>Saltar 0</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="335"/>
        <source>Skip 1</source>
        <translation>Saltar 1</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="336"/>
        <source>Skip 10</source>
        <translation>Saltar 10</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="337"/>
        <source>Skip 100</source>
        <translation>Saltar 100</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="338"/>
        <location filename="../serverInformation.cpp" line="344"/>
        <location filename="../serverInformation.cpp" line="348"/>
        <source>Stop refreshing</source>
        <translation>Detener refrescado</translation>
    </message>
    <message>
        <source>Global Variables</source>
        <translation type="obsolete">Variables Globales</translation>
    </message>
    <message>
        <source>Global Status</source>
        <translation type="obsolete">Estado Global</translation>
    </message>
    <message>
        <source>Session Variables</source>
        <translation type="obsolete">Variables de Sesión</translation>
    </message>
    <message>
        <source>Session Status</source>
        <translation type="obsolete">Estado de la Sesión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="340"/>
        <location filename="../serverInformation.cpp" line="341"/>
        <source>Variables</source>
        <translation>Variables</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="343"/>
        <location filename="../serverInformation.cpp" line="345"/>
        <location filename="../serverInformation.cpp" line="346"/>
        <location filename="../serverInformation.cpp" line="349"/>
        <location filename="../serverInformation.cpp" line="644"/>
        <source>Server Graphics</source>
        <translation>Gráficos del Servidor</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="351"/>
        <location filename="../serverInformation.cpp" line="352"/>
        <source>HDD Usage</source>
        <translation>Uso del HDD</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="354"/>
        <source>Filter</source>
        <translation>Filtro</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="355"/>
        <source>Show global variables</source>
        <translation>Mostrar variables globales</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="356"/>
        <source>Show global status</source>
        <translation>Mostrar el estado global</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="357"/>
        <source>Show session status</source>
        <translation>Mostrar estado de la sessión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="358"/>
        <source>Show session variables</source>
        <translation>Mostrar variables de sessión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="359"/>
        <source>Filter:</source>
        <translation>Filtro:</translation>
    </message>
    <message>
        <source>Three character at least</source>
        <translation type="obsolete">Tres caracters como mínimo</translation>
    </message>
    <message>
        <source>queries</source>
        <translation type="obsolete">consultas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="329"/>
        <source>Show server status</source>
        <translation>Mostrar estado del servidor</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="330"/>
        <source>Show slow queries</source>
        <translation>Mostrar las consultas lentas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="360"/>
        <source>Three characters at least</source>
        <translation>Tres caracteres como mínimo</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="361"/>
        <source>Full screen</source>
        <translation>Pantalla completa</translation>
    </message>
    <message>
        <source>HDD Usage Graphics</source>
        <translation type="obsolete">Gráfico de uso de HDD</translation>
    </message>
    <message>
        <source>Executed Queries</source>
        <translation type="obsolete">Consultas Ejecutadas</translation>
    </message>
    <message>
        <source>Data Sent/Received</source>
        <translation type="obsolete">Datos Enviados/Recibidos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="383"/>
        <source>Data sent in MB.</source>
        <translation>Datos enviados en MB.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="385"/>
        <location filename="../serverInformation.cpp" line="399"/>
        <source>Transfer rate: %1 Kb per second.</source>
        <translation>Radio de transferencia: %1 Kb por segundo.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="397"/>
        <source>Data received in MB.</source>
        <translation>Datos recibidos e MB.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="402"/>
        <source>Miscellaneous values.</source>
        <translation>Valores miceláneos.</translation>
    </message>
    <message>
        <source>Other</source>
        <translation type="obsolete">Otros</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="493"/>
        <source>Database sizes description.</source>
        <translation>Descripción de los tamaños de las bases de datos.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="497"/>
        <location filename="../serverInformation.cpp" line="507"/>
        <source>Database</source>
        <translation>Base de Datos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="498"/>
        <location filename="../serverInformation.cpp" line="508"/>
        <source>Total</source>
        <translation>Total</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="499"/>
        <location filename="../serverInformation.cpp" line="509"/>
        <source>Data</source>
        <translation>Datos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="500"/>
        <location filename="../serverInformation.cpp" line="510"/>
        <source>Indexes</source>
        <translation>Índices</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="501"/>
        <source>Tables</source>
        <translation>Tablas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="502"/>
        <location filename="../serverInformation.cpp" line="511"/>
        <source>Rows</source>
        <translation>Filas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="506"/>
        <source>Detailed size table description. Table size greater than %1 MB.</source>
        <translation>Descripción detallada del tamaño de las tablas. Tamaño de tablas mayores a %1 MB.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="507"/>
        <source>Table name</source>
        <translation>Nombre de la tabla</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="519"/>
        <source>Pending.</source>
        <translation>Pendiente.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="523"/>
        <location filename="../serverInformation.cpp" line="547"/>
        <source>There was an error determinating the DBMS type.</source>
        <translation>Hubo un error al determinar el tipo de DBMS.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="532"/>
        <source>Main server data.</source>
        <translation>Servidor principal de datos.</translation>
    </message>
    <message>
        <source>Uptime in days</source>
        <translation type="obsolete">Tiempo encendido en días</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="542"/>
        <source>Variable</source>
        <translation>Variable</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="542"/>
        <source>Value</source>
        <translation>Valor</translation>
    </message>
    <message>
        <source>The number of days that the server has been up.</source>
        <translation type="obsolete">El número de días que el servidor ha estado en funcionamiento.</translation>
    </message>
    <message>
        <source>Description</source>
        <translation type="obsolete">Descripción</translation>
    </message>
    <message>
        <source>Rate of aborted clients per day.</source>
        <translation type="obsolete">Tasa de clientes abortados por día.</translation>
    </message>
    <message>
        <source>Rate of rollbacks per second.</source>
        <translation type="obsolete">Tasa de rollbacks por segundo.</translation>
    </message>
    <message>
        <source>The number of seconds that determinate a slow query.</source>
        <translation type="obsolete">El número de segundos para determinar que una consulta es lenta.</translation>
    </message>
    <message>
        <source>Physical reads miss rate</source>
        <translation type="obsolete">Taza de fallo de lecturas físicas</translation>
    </message>
    <message>
        <source>Aborted clients</source>
        <translation type="obsolete">Clientes abortados</translation>
    </message>
    <message>
        <source>The number of connections that were aborted because the client died without closing the connection properly.</source>
        <translation type="obsolete">El número de conexiones que han sido abortadas debido a que el cliente murió sin cerrar la conexión correctamente.</translation>
    </message>
    <message>
        <source>Aborted clients per day</source>
        <translation type="obsolete">Clientes abortados por día</translation>
    </message>
    <message>
        <source>Aborted connections</source>
        <translation type="obsolete">Conexiones abortadas</translation>
    </message>
    <message>
        <source>The number of failed attempts to connect to the database server.</source>
        <translation type="obsolete">El número de intentos fallidos de conectarse al servidor de base de datos.</translation>
    </message>
    <message>
        <source>Executed rollbacks</source>
        <translation type="obsolete">Rollbacks ejecutados</translation>
    </message>
    <message>
        <source>The number of times each rollback statement has been executed.</source>
        <translation type="obsolete">El número de veces que cada sentencia de rollback se ha ejecutado.</translation>
    </message>
    <message>
        <source>Executed queries</source>
        <translation type="obsolete">Consultas ejecutadas</translation>
    </message>
    <message>
        <source>The number of statements executed by the server.</source>
        <translation type="obsolete">El número de sentencias ejecutadas por el servidor.</translation>
    </message>
    <message>
        <source>Rollbacks per second</source>
        <translation type="obsolete">Rollbacks por segundo</translation>
    </message>
    <message>
        <source>Temporary disk tables created</source>
        <translation type="obsolete">Tablas temporales de disco creadas</translation>
    </message>
    <message>
        <source>The number of internal on-disk temporary tables created by the server while executing statements.</source>
        <translation type="obsolete">El número de tablas temporales en disco internas creadas por el servidor mientras ejecuta las sentencias.</translation>
    </message>
    <message>
        <source>Free cache memory</source>
        <translation type="obsolete">Memoria cache libre</translation>
    </message>
    <message>
        <source>The amount of free memory for the query cache.</source>
        <translation type="obsolete">La cantidad de memoria libre para la caché de consultas.</translation>
    </message>
    <message>
        <source>Joins with full table scan</source>
        <translation type="obsolete">Joins con escaneo completo de tabla</translation>
    </message>
    <message>
        <source>The number of joins that perform table scans because they do not use indexes.</source>
        <translation type="obsolete">El número de joins que realizan escaneos de tablas porque que no utilizan índices.</translation>
    </message>
    <message>
        <source>Log slow queries</source>
        <translation type="obsolete">Guardar consultas lentas</translation>
    </message>
    <message>
        <source>Is the slow queries logging enabled?</source>
        <translation type="obsolete">¿Está el loggeo de consultas habilitado?</translation>
    </message>
    <message>
        <source>Slow queries time in seconds</source>
        <translation type="obsolete">Tiempo de consultas lentas en segundos</translation>
    </message>
    <message>
        <source>Count of slow queries</source>
        <translation type="obsolete">Conteo de consultas lentas</translation>
    </message>
    <message>
        <source>The number of queries that have taken more than the allowed time.</source>
        <translation type="obsolete">El número de consultas que han tardado más que el tiempo permitido.</translation>
    </message>
    <message>
        <source>Idle connections</source>
        <translation type="obsolete">Conexiones inactivas</translation>
    </message>
    <message>
        <source>The number of connections that has been idle for more than 30 seconds.</source>
        <translation type="obsolete">El número de conexiones que ha estado inactivo durante más de 30 segundos.</translation>
    </message>
    <message>
        <source>Max connections aviable</source>
        <translation type="obsolete">Cantidad máxima de conexiones disponibles</translation>
    </message>
    <message>
        <source>The maximum permitted number of simultaneous client connections.</source>
        <translation type="obsolete">El número máximo permitido de conexiones de cliente simultáneas.</translation>
    </message>
    <message>
        <source>Used connections</source>
        <translation type="obsolete">Conexiones usadas</translation>
    </message>
    <message>
        <source>The maximum number of connections that have been in use simultaneously since the server started.</source>
        <translation type="obsolete">El número máximo de conexiones que han sido utilizadas simultáneamente desde que el servidor se inició.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="537"/>
        <source>Average of slow queries per day since server started.</source>
        <translation>Promedio de consultas lentas por día desde que el servidor inició.</translation>
    </message>
    <message>
        <source>Average per day since server started.</source>
        <translation type="obsolete">Promedio por día desde que el servidor inició.</translation>
    </message>
    <message>
        <source>Date</source>
        <translation type="obsolete">Fecha</translation>
    </message>
    <message>
        <source>Day</source>
        <translation type="obsolete">Día</translation>
    </message>
    <message>
        <source>Total queries</source>
        <translation type="obsolete">Total de consultas</translation>
    </message>
    <message>
        <source>Average (in seconds)</source>
        <translation type="obsolete">Promedio (en segundos)</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="542"/>
        <source>Uptime in hours</source>
        <translation>Tiempo encendido en horas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="626"/>
        <source>Global status</source>
        <translation>Estado global</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="628"/>
        <source>Session status</source>
        <translation>Estado de sesión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="630"/>
        <source>Global variables</source>
        <translation>Variables globales</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="632"/>
        <source>Session variables</source>
        <translation>Variables de sesión</translation>
    </message>
    <message>
        <source>Average</source>
        <translation type="obsolete">Promedio</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="561"/>
        <source>Slow queries since server started.</source>
        <translation>Consultas lentas desde que el servidor inició.</translation>
    </message>
</context>
<context>
    <name>Statements</name>
    <message>
        <location filename="../statements.cpp" line="36"/>
        <source>Executed statements</source>
        <translation>Sentencias ejecutadas</translation>
    </message>
    <message>
        <location filename="../statements.cpp" line="40"/>
        <source>Statements</source>
        <translation>Sentencias</translation>
    </message>
    <message>
        <location filename="../statements.cpp" line="61"/>
        <source>Copy</source>
        <translation>Copiar</translation>
    </message>
    <message>
        <location filename="../statements.cpp" line="63"/>
        <source>Delete</source>
        <translation>Borrar</translation>
    </message>
</context>
<context>
    <name>StaticFunctions</name>
    <message>
        <location filename="../staticfunctions.cpp" line="132"/>
        <source>Absolute value of numeric.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="133"/>
        <source>Cube root of numeric.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="134"/>
        <location filename="../staticfunctions.cpp" line="135"/>
        <source>Smallest integer not less than numeric.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="136"/>
        <source>Radians to degrees.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="137"/>
        <source>Integer quotient of y/x.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="138"/>
        <source>Exponential.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="139"/>
        <source>Largest integer not greater than numeric.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="140"/>
        <source>Natural logarithm.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="141"/>
        <source>Base 10 logarithm.&lt;br/ &gt;Logarithm to base b.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="142"/>
        <source>Remainder of y/x.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="143"/>
        <source>PI constant.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="144"/>
        <source>a raised to the power of b.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="145"/>
        <source>Degrees to radians.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="146"/>
        <source>Random value in the range 0.0 &lt;= x &lt; 1.0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="147"/>
        <source>Round to nearest integer.&lt;br /&gt;Round to s decimal places.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="148"/>
        <source>Set seed for subsequent random() calls (value between -1.0 and 1.0, inclusive).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="149"/>
        <source>Sign of the argument (-1, 0, +1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="150"/>
        <source>Square root.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="151"/>
        <source>Truncate toward zero.&lt;br /&gt;Truncate to s decimal places.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="152"/>
        <source>Return the bucket to which operand would be assigned in an equidepth histogram with count buckets, in the range b1 to b2.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="155"/>
        <source>ASCII code of the first character of the argument.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="156"/>
        <source>Remove the longest string consisting only of characters in characters (a space by default) from the start and end of string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="157"/>
        <source>Character with the given code. bytes.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="158"/>
        <source>Concatenate all arguments. NULL arguments are ignored.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="159"/>
        <source>Concatenate all but first arguments with separators. The first parameter is used as a separator. NULL arguments are ignored.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="160"/>
        <source>Convert string to dest_encoding. conversions.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="161"/>
        <source>Convert string to the database encoding. The original encoding is specified bysrc_encoding. The string must be valid in this encoding.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="162"/>
        <source>Convert string to dest_encoding.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="163"/>
        <source>Decode binary data from textual representation in string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="164"/>
        <source>Encode binary data into a textual representation.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="165"/>
        <source>Format a string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="166"/>
        <source>Convert the first letter of each word to upper case and the rest to lower case.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="167"/>
        <source>Return first n characters in the string. When nis negative, return all but last |n| characters.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="168"/>
        <location filename="../staticfunctions.cpp" line="193"/>
        <source>Number of characters in string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="169"/>
        <source>Fill up the string to length length by prepending the characters fill (a space by default). If the string is already longer thanlength then it is truncated (on the right).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="170"/>
        <source>Remove the longest string containing only characters from characters (a space by default) from the start of string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="171"/>
        <source>Calculates the MD5 hash of string, returning the result in hexadecimal.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="172"/>
        <source>Current client encoding name.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="173"/>
        <source>Return the given string suitably quoted to be used as an identifier in an SQL statement string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="174"/>
        <source>Return the given string suitably quoted to be used as a string literal in an SQL statement string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="175"/>
        <source>Return the given string suitably quoted to be used as a string literal in an SQL statement string; or, if the argument is null, return NULL.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="176"/>
        <source>Return all captured substrings resulting from matching a POSIX regular expression against the string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="177"/>
        <source>Replace substring(s) matching a POSIX regular expression.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="178"/>
        <location filename="../staticfunctions.cpp" line="179"/>
        <source>Split string using a POSIX regular expression as the delimiter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="180"/>
        <source>Repeat string the specified number of times.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="181"/>
        <source>Replace all occurrences in string of substring from with substring to.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="182"/>
        <source>Return reversed string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="183"/>
        <source>Return last n characters in the string. When nis negative, return all but first |n| characters.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="184"/>
        <source>Fill up the string to length length by appending the characters fill (a space by default).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="185"/>
        <source>Remove the longest string containing only characters from characters (a space by default) from the end of string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="186"/>
        <source>Split string on delimiter and return the given field (counting from one).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="187"/>
        <source>Location of specified substring (same as position(substring in string), but note the reversed argument order).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="188"/>
        <source>Extract substring (same as substring(string from from forcount)).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="189"/>
        <source>Convert string to ASCII from another encoding.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="190"/>
        <source>Convert number to its equivalent hexadecimal representation.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="191"/>
        <source>Any character in string that matches a character in the from set is replaced by the corresponding character in the to set.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="192"/>
        <source>Number of bits in string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="194"/>
        <source>Convert string to lower case.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="195"/>
        <source>Number of bytes in string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="196"/>
        <source>Replace substring.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="197"/>
        <source>Location of specified substring.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="198"/>
        <source>Extract substring.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="199"/>
        <source>Remove the longest string containing only the characters (a space by default) from the start/end/both ends of the string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="200"/>
        <source>Convert string to upper case.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="961"/>
        <source>Returns the absolute value of &lt;b&gt;X&lt;/b&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="964"/>
        <source>Adds expr2 to expr1 and returns the result.&lt;br /&gt;expr1 is a time or datetime expression, and expr2 is a time expression.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="971"/>
        <source>Returns the average value of expr.&lt;br /&gt;The DISTINCT option can be used as of MySQL 5.0.3 to return the average of the distinct values of expr.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="979"/>
        <source>Takes an expression of any type and produces a result value of a specified type.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="980"/>
        <location filename="../staticfunctions.cpp" line="981"/>
        <source>Returns the smallest integer value not less than X</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="982"/>
        <source>Returns the length of the string str, measured in characters. A multi-byte character counts as a single character.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="989"/>
        <source>Returns the string that results from concatenating the arguments.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="995"/>
        <source>Returns a count of the number of non-NULL values of expr in the rows retrieved by a SELECT statement.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="997"/>
        <location filename="../staticfunctions.cpp" line="998"/>
        <source>Returns the current date as a value in &apos;YYYY-MM-DD&apos; or YYYYMMDD format, depending on whether the function is used in a string or numeric context.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1000"/>
        <location filename="../staticfunctions.cpp" line="1081"/>
        <source>Returns the current date and time as a value in &apos;YYYY-MM-DD HH:MM:SS&apos; or YYYYMMDDHHMMSS.uuuuuu format, &lt;br /&gt;depending on whether the function is used in a string or numeric context.&lt;br /&gt;The value is expressed in the current time zone.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1001"/>
        <source>Returns the user name and host name combination for the MySQL account that the server used to authenticate the current client.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1003"/>
        <location filename="../staticfunctions.cpp" line="1005"/>
        <source>These functions perform date arithmetic.&lt;br /&gt;The date argument specifies the starting date or datetime value.&lt;br /&gt;expr is an expression specifying the interval value to be added or subtracted from the starting date.&lt;br /&gt;expr is a string; it may start with a â-â for negative intervals.&lt;br /&gt;unit is a keyword indicating the units in which the expression should be interpreted.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1004"/>
        <source>Returns a string containing the date in the specified format.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1006"/>
        <source>Returns expr1 - expr2 expressed as a value in days from one date to the other.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1011"/>
        <source>Returns the name of the weekday for date.&lt;br /&gt;The language used for the name is controlled by the value of the lc_time_names system variable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1030"/>
        <source>Returns the largest integer value not greater than x.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1031"/>
        <source>Formats the number X to a format like &apos;#,###,###.##&apos;, rounded to D decimal places, and returns the result as a string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1034"/>
        <source>Returns a representation of the unix_timestamp argument as a value in &apos;YYYY-MM-DD HH:MM:SS&apos; or YYYYMMDDHHMMSS.uuuuuu format,&lt;br /&gt;depending on whether the function is used in a string or numeric context.&lt;br /&gt;If format is given, the result is formatted according to the format string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1038"/>
        <source>This function returns a string result with the concatenated non-NULL values from a group. It returns NULL if there are no non-NULL values.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1043"/>
        <source>If expr1 is not NULL, IFNULL() returns expr1; otherwise it returns expr2.&lt;br /&gt;IFNULL() returns a numeric or string value, depending on the context in which it is used.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1044"/>
        <source>Given the dotted-quad representation of an IPv4 network address as a string, returns an integer that represents the numeric value of the address in network byte order (big endian).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1046"/>
        <source>Returns the position of the first occurrence of substring substr in string str.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1050"/>
        <source>If expr is NULL, ISNULL() returns 1, otherwise it returns 0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1053"/>
        <source>Returns the string str with all characters changed to lowercase according to the current character set mapping.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1056"/>
        <source>Returns the length of the string str, measured in bytes. &lt;br /&gt;A multi-byte character counts as multiple bytes.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1060"/>
        <source>Returns the position of the first occurrence of substring substr in string str, starting at position pos.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1064"/>
        <source>Returns the string str with all characters changed to lowercase according to the current character set mapping. </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1065"/>
        <source>Returns the string str, left-padded with the string padstr to a length of len characters.&lt;br /&gt;If str is longer than len, the return value is shortened to len characters.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1071"/>
        <source>Returns the maximum value of expr.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1072"/>
        <source>Calculates an MD5 128-bit checksum for the string. The value is returned as a string of 32 hex digits, or NULL if the argument was NULL.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1073"/>
        <source>Returns the microseconds from the time or datetime expression expr as a number in the range from 0 to 999999.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1074"/>
        <location filename="../staticfunctions.cpp" line="1124"/>
        <location filename="../staticfunctions.cpp" line="1126"/>
        <source>The forms without a len argument return a substring from string str starting at position pos. &lt;br /&gt;The forms with a len argument return a substring len characters long from string str, starting at position pos.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1075"/>
        <source>Returns the minimum value of expr.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1078"/>
        <source>Returns the month for date, in the range 1 to 12 for January to December.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1082"/>
        <source>Returns NULL if expr1 = expr2 is true, otherwise returns expr1.&lt;br /&gt;This is the same as CASE WHEN expr1 = expr2 THEN NULL ELSE expr1 END.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1097"/>
        <source>Returns a random floating-point value v in the range 0 &lt;= v &lt; 1.0. If a constant integer argument N is specified, it is used as the seed value, which produces a repeatable sequence of column values.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1102"/>
        <source>Returns the number of rows changed, deleted, or inserted by the last statement.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1103"/>
        <source>Returns the string str, right-padded with the string padstr to a length of len characters.&lt;br /&gt;If str is longer than len, the return value is shortened to len characters.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1105"/>
        <source>Returns the seconds argument, converted to hours, minutes, and seconds, as a TIME value.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1125"/>
        <source>Returns the substring from string str before count occurrences of the delimiter delim. &lt;br /&gt;If count is positive, everything to the left of the final delimiter (counting from the left) is returned. &lt;br /&gt;If count is negative, everything to the right of the final delimiter (counting from the right) is returned.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1127"/>
        <source>Returns expr1 â expr2 expressed as a value in the same format as expr1.&lt;br /&gt;expr1 is a time or datetime expression, and expr2 is a time expression.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1132"/>
        <source>Returns the time argument, converted to seconds.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1133"/>
        <source>Returns expr1 - expr2 expressed as a time value.&lt;br /&gt;expr1 and expr2 are time or date-and-time expressions, but both must be of the same type.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1135"/>
        <source>Returns datetime_expr2 - datetime_expr1, where datetime_expr1 and datetime_expr2 are date or datetime expressions.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1136"/>
        <source>Returns a day number (the number of days since year 0).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1137"/>
        <source>Returns the string str with all remstr prefixes or suffixes removed.&lt;br /&gt;If none of the specifiers BOTH, LEADING, or TRAILING is given, BOTH is assumed. remstr is optional and, if not specified, spaces are removed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1138"/>
        <source>Returns the number X, truncated to D decimal places.&lt;br /&gt;If D is 0, the result has no decimal point or fractional part.&lt;br /&gt;D can be negative to cause D digits left of the decimal point of the value X to become zero.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1139"/>
        <source>Returns the string str with all characters changed to uppercase according to the current character set mapping.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1143"/>
        <source>If called with no argument, returns a Unix timestamp (seconds since &apos;1970-01-01 00:00:00&apos; UTC) as an unsigned integer.&lt;br /&gt;If UNIX_TIMESTAMP() is called with a date argument, it returns the value of the argument as seconds since &apos;1970-01-01 00:00:00&apos; UTC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1146"/>
        <source>Returns the current MySQL user name and host name.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1154"/>
        <source>Returns a string that indicates the MySQL server version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1161"/>
        <source>If expr is greater than or equal to min and expr is less than or equal to max, BETWEEN returns 1, otherwise it returns 0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1935"/>
        <source>Quote string with slashes</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1993"/>
        <source>Create an array</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1998"/>
        <source>Compares array1 against array2 and returns the difference.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2003"/>
        <source>Fills an array with num entries of the value of the value parameter, keys starting at the start_index parameter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2005"/>
        <source>Filters elements of an array using a callback function.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2006"/>
        <source>Exchanges all keys with their associated values in an array.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2013"/>
        <source>Returns the keys, numeric and string, from the input array.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2015"/>
        <source>Merge one or more arrays.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2019"/>
        <source>Pop the element off the end of array</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2027"/>
        <source>Searches the array for a given value and returns the corresponding key if successful.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2029"/>
        <source>Extract a slice of the array</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2030"/>
        <source>Remove a portion of the array and replace it with something else</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2031"/>
        <source>Calculate the sum of values in an array.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2040"/>
        <source>Return all the values of an array.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2046"/>
        <source>Sort an array in reverse order and maintain index association</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2049"/>
        <source>Sort an array and maintain index association.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2058"/>
        <source>Encodes data with MIME base64</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2250"/>
        <source>Calls the callback given by the first parameter and passes the remaining parameters as arguments.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2267"/>
        <source>Split a string into smaller chunks</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2281"/>
        <source>Close directory handle</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2316"/>
        <source>Counts all elements in an array, or something in an object.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2456"/>
        <source>Format a local time/date</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2622"/>
        <source>Generates a backtrace.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2628"/>
        <source>Defines a named constant</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2646"/>
        <source>Returns parent directory&apos;s path</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2760"/>
        <source>Output one or more strings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2817"/>
        <source>Determine whether a variable is empty</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2845"/>
        <source>Sets which PHP errors are reported.&lt;br /&gt;E_ERROR, E_WARNING, E_PARSE, E_NOTICE, E_CORE_ERROR&lt;br /&gt;, E_CORE_WARNING, E_COMPILE_ERROR, E_COMPILE_WARNING, E_USER_ERROR, E_USER_WARNING&lt;br /&gt;, E_USER_NOTICE, E_STRICT, E_RECOVERABLE_ERROR, E_DEPRECATED, E_USER_DEPRECATED, E_ALL</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2883"/>
        <source>Split a string by string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2960"/>
        <source>Closes an open file pointer</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3002"/>
        <source>Reads entire file into an array</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3003"/>
        <source>Checks whether a file or directory exists</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3004"/>
        <source>Reads entire file into a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3005"/>
        <source>Write a string to a file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3020"/>
        <source>Gets file size</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3028"/>
        <source>Filters a variable with a specified filter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3042"/>
        <source>Opens file or URL</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3049"/>
        <source>Binary-safe file read</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3096"/>
        <source>Checks the list of defined functions, both built-in (internal) and user-defined, for function_name.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3097"/>
        <source>Binary-safe file write.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3529"/>
        <source>Send a raw HTTP header</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4617"/>
        <source>Join array elements with a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4619"/>
        <source>Searches haystack for needle using loose Comparision unless strict is set.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4620"/>
        <source>Includes and evaluates the specified file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4621"/>
        <source>Includes and evaluates the specified file during the execution of the script</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4664"/>
        <source>Sets the value of a configuration option.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4685"/>
        <source>Finds whether a variable is an array.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4688"/>
        <source>Tells whether the filename is a directory</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4700"/>
        <source>Finds whether a variable is NULL</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4701"/>
        <source>Finds whether a variable is a number or a numeric string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4722"/>
        <source>Determine if a variable is set and is not NULL</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4744"/>
        <source>Decodes a JSON string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4763"/>
        <source>Sort an array by key in reverse order</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4764"/>
        <source>Sort an array by key</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4886"/>
        <source>Send mail</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5095"/>
        <source>Calculate the md5 hash of a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5111"/>
        <source> Return current Unix timestamp with microseconds.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5660"/>
        <source>Format a number with grouped thousands</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5673"/>
        <source>Get current buffer contents and delete current output buffer.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5684"/>
        <source>Turn on output buffering.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5880"/>
        <source>Open directory handle</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6270"/>
        <source>Gets the current PHP version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6315"/>
        <source>Searches subject for a match to the regular expression given in pattern.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6318"/>
        <source>Perform a regular expression search and replace</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6323"/>
        <source>Prints human-readable information about a variable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6530"/>
        <source>Read entry from directory handle</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6531"/>
        <source>Outputs a file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6578"/>
        <source>Includes and evaluates the specified file. Halt the script whereas include() emits a warning</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6579"/>
        <source>Identical to require() except PHP will check if the file has already been included, and if so, not include (require) it again</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6589"/>
        <source>Rounds a float</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6612"/>
        <source>Strip whitespace (or other characters) from the end of a string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6768"/>
        <source>Limits the maximum execution time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6778"/>
        <source>Execute command via shell and return the complete output as a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6884"/>
        <source>This function sorts an array. Elements will be arranged from lowest to highest when this function has completed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7100"/>
        <source>Replace all occurrences of the search string with the replacement string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7162"/>
        <source>Get string length</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7168"/>
        <source>Find the position of the first occurrence of a substring in a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7182"/>
        <source>Return part of a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7528"/>
        <source>Return current Unix timestamp</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7552"/>
        <source>Strip whitespace (or other characters) from the beginning and end of a string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7555"/>
        <source>Uppercase the first character of each word in a string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7584"/>
        <source>Generate a unique ID</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7590"/>
        <source>Unset a given variable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7596"/>
        <source>Sort an array by values using a user-defined Comparision function</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7597"/>
        <source>Converts a string with ISO-8859-1 characters encoded with UTF-8 to single-byte ISO-8859-1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7601"/>
        <source>Dumps information about a variable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8092"/>
        <source>A rule that allows websites to download and use fonts other than the &apos;web-safe&apos; fonts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8093"/>
        <source>Specifies the animation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8094"/>
        <source>Allows more precise alignment of elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8095"/>
        <source>Specifies how an inline-level element is aligned with respect to its parent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8096"/>
        <source>A shorthand property for all the animation properties below, except the animation-play-state property</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8097"/>
        <source>Specifies when the animation will start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8098"/>
        <source>Specifies whether or not the animation should play in reverse on alternate cycles</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8099"/>
        <source>Specifies how many seconds or milliseconds an animation takes to complete one cycle</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8100"/>
        <source>Specifies the number of times an animation should be played</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8101"/>
        <source>Specifies a name for the @keyframes animation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8102"/>
        <source>Specifies whether the animation is running or paused</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8103"/>
        <source>Specifies the speed curve of the animation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8104"/>
        <source>Allows you to make an element look like a standard user interface element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8105"/>
        <source>Defines whether or not an element should be visible when not facing the screen</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8106"/>
        <source>Sets all the background properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8107"/>
        <source>Sets whether a background image is fixed or scrolls with the rest of the page</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8108"/>
        <source>Specifies the painting area of the background</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8109"/>
        <source>Sets the background color of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8110"/>
        <source>Sets the background image for an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8111"/>
        <source>Specifies the positioning area of the background images</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8112"/>
        <source>Sets the starting position of a background image</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8113"/>
        <source>Sets how a background image will be repeated</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8114"/>
        <source>Specifies the size of the background images</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8115"/>
        <source>Allows repositioning of the dominant-baseline relative to the dominant-baseline</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8116"/>
        <source>Specifies the label of the bookmark</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8117"/>
        <source>Specifies the level of the bookmark</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8118"/>
        <source>Specifies the target of the bookmark link</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8119"/>
        <source>Sets all the border properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8120"/>
        <source>Sets all the bottom border properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8121"/>
        <source>Sets the color of the bottom border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8122"/>
        <source>Defines the shape of the border of the bottom-left corner</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8123"/>
        <source>Defines the shape of the border of the bottom-right corner</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8124"/>
        <source>Sets the style of the bottom border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8125"/>
        <source>Sets the width of the bottom border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8126"/>
        <source>Specifies whether or not table borders should be collapsed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8127"/>
        <source>Sets the color of the four borders</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8128"/>
        <source>A shorthand property for setting all the border-image-* properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8129"/>
        <source>Specifies the amount by which the border image area extends beyond the border box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8130"/>
        <source>Specifies whether the image-border should be repeated, rounded or stretched</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8131"/>
        <source>Specifies the inward offsets of the image-border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8132"/>
        <source>Specifies an image to be used as a border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8133"/>
        <source>Specifies the widths of the image-border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8134"/>
        <source>Sets all the left border properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8135"/>
        <source>Sets the color of the left border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8136"/>
        <source>Sets the style of the left border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8137"/>
        <source>Sets the width of the left border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8138"/>
        <source>A shorthand property for setting all the four border-*-radius properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8139"/>
        <source>Sets all the right border properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8140"/>
        <source>Sets the color of the right border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8141"/>
        <source>Sets the style of the right border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8142"/>
        <source>Sets the width of the right border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8143"/>
        <source>Specifies the distance between the borders of adjacent cells</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8144"/>
        <source>Sets the style of the four borders</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8145"/>
        <source>Sets all the top border properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8146"/>
        <source>Sets the color of the top border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8147"/>
        <source>Defines the shape of the border of the top-left corner</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8148"/>
        <source>Defines the shape of the border of the top-right corner</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8149"/>
        <source>Sets the style of the top border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8150"/>
        <source>Sets the width of the top border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8151"/>
        <source>Sets the width of the four borders</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8152"/>
        <source>Specifies the bottom position of a positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8153"/>
        <source>Specifies how to align the child elements of a box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8154"/>
        <location filename="../staticfunctions.cpp" line="8294"/>
        <location filename="../staticfunctions.cpp" line="8320"/>
        <source> </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8155"/>
        <source>Specifies in which direction the children of a box are displayed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8156"/>
        <source>Specifies whether the children of a box is flexible or inflexible in size</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8157"/>
        <source>Assigns flexible elements to flex groups</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8158"/>
        <source>Specifies whether columns will go onto a new line whenever it runs out of space in the parent box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8159"/>
        <source>Specifies the display order of the child elements of a box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8160"/>
        <source>Specifies whether the children of a box should be laid out horizontally or vertically</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8161"/>
        <source>Specifies the horizontal position in horizontal boxes and the vertical position in vertical boxes</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8162"/>
        <source>Attaches one or more drop-shadows to the box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8163"/>
        <source>Allows you to define certain elements to fit an area in a certain way</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8164"/>
        <source>Specifies the placement of a table caption</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8165"/>
        <source>Specifies which sides of an element where other floating elements are not allowed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8166"/>
        <source>Clips an absolutely positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8167"/>
        <source>Sets the color of text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8168"/>
        <source>Permits the specification of a source color profile other than the default</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8169"/>
        <source>Specifies the number of columns an element should be divided into</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8170"/>
        <source>Specifies how to fill columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8171"/>
        <source>Specifies the gap between the columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8172"/>
        <source>A shorthand property for setting all the column-rule-* properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8173"/>
        <source>Specifies the color of the rule between columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8174"/>
        <source>Specifies the style of the rule between columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8175"/>
        <source>Specifies the width of the rule between columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8176"/>
        <source>Specifies how many columns an element should span across</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8177"/>
        <source>Specifies the width of the columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8178"/>
        <source>A shorthand property for setting column-width and column-count</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8179"/>
        <source>Used with the :before and :after pseudo-elements, to insert generated content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8180"/>
        <source>Increments one or more counters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8181"/>
        <source>Creates or resets one or more counters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8182"/>
        <source>Allows a replaced element to be just a rectangular area of an object, instead of the whole object</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8183"/>
        <source>Specifies the type of cursor to be displayed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8184"/>
        <source>Specifies the text direction/writing direction</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8185"/>
        <source>Specifies how a certain HTML element should be displayed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8186"/>
        <source>Specifies a scaled-baseline-table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8187"/>
        <source>Sets the alignment point of the drop initial for the primary connection point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8188"/>
        <source>Sets which alignment line within the initial line box is used at the primary connection point with the initial letter box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8189"/>
        <source>Sets the alignment point of the drop initial for the secondary connection point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8190"/>
        <source>Sets which alignment line within the initial line box is used at the secondary connection point with the initial letter box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8191"/>
        <source>Controls the partial sinking of the initial letter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8192"/>
        <source>Activates a drop-initial effect</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8193"/>
        <source>Specifies whether or not to display borders and background on empty cells in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8194"/>
        <source>Gives a hint for how to scale a replaced element if neither its width nor its height property is auto</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8195"/>
        <source>Determines the alignment of the object inside the box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8196"/>
        <source>Specifies whether or not a box should float</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8197"/>
        <source>Pushes floated elements in the opposite direction of the where they have been floated with float</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8198"/>
        <source>Sets all the font properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8199"/>
        <source>Specifies the font family for text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8200"/>
        <source>Specifies the font size of text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8201"/>
        <source>Preserves the readability of text when font fallback occurs</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8202"/>
        <source>Selects a normal, condensed, or expanded face from a font family</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8203"/>
        <source>Specifies the font style for text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8204"/>
        <source>Specifies whether or not a text should be displayed in a small-caps font</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8205"/>
        <source>Specifies the weight of a font</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8206"/>
        <source>Specifies the width of each column in a grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8207"/>
        <source>Specifies the height of each column in a grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8208"/>
        <source>Specifies whether a punctuation character may be placed outside the line box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8209"/>
        <source>Sets the height of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8210"/>
        <source>Specifies the minimum number of characters in a hyphenated word after the hyphenation character</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8211"/>
        <source>Specifies the minimum number of characters in a hyphenated word before the hyphenation character</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8212"/>
        <source>Specifies a string that is shown when a hyphenate-break occurs</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8213"/>
        <source>Indicates the maximum number of successive hyphenated lines in an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8214"/>
        <source>Specifies a comma-separated list of external resources that can help the browser determine hyphenation points</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8215"/>
        <source>Sets how to split words to improve the layout of paragraphs</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8216"/>
        <source>Provides the author the ability to style an element with an iconic equivalent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8217"/>
        <source>Specifies a rotation in the right or clockwise direction that a user agent applies to an image</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8218"/>
        <source>Specifies the correct resolution of images</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8219"/>
        <source>Sets which line of a multi-line inline block align with the previous and next inline elements within a line</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8220"/>
        <source>Specifies the left position of a positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8221"/>
        <source>Increases or decreases the space between characters in a text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8222"/>
        <source>Sets the line height</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8223"/>
        <source>A shorthand property for setting the line-stacking-strategy, line-stacking-ruby, and line-stacking-shift properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8224"/>
        <source>Sets the line stacking method for block elements containing ruby annotation elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8225"/>
        <source>Sets the line stacking method for block elements containing elements with base-shift</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8226"/>
        <source>Sets the line stacking strategy for stacked line boxes within a containing block element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8227"/>
        <source>Sets all the properties for a list in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8228"/>
        <source>Specifies an image as the list-item marker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8229"/>
        <source>Specifies if the list-item markers should appear inside or outside the content flow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8230"/>
        <source>Specifies the type of list-item marker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8231"/>
        <source>Sets all the margin properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8232"/>
        <source>Sets the bottom margin of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8233"/>
        <source>Sets the left margin of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8234"/>
        <source>Sets the right margin of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8235"/>
        <source>Sets the top margin of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8236"/>
        <source>A shorthand property for setting the mark-before and mark-after properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8237"/>
        <location filename="../staticfunctions.cpp" line="8238"/>
        <source>Allows named markers to be attached to the audio stream</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8239"/>
        <source>Adds crop and/or cross marks to the document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8240"/>
        <source>Sets the direction of the moving content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8241"/>
        <source>Sets how many times the content move</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8242"/>
        <source>Sets how fast the content scrolls</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8243"/>
        <source>Sets the style of the moving content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8244"/>
        <source>Sets the maximum height of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8245"/>
        <source>Sets the maximum width of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8246"/>
        <source>Sets the minimum height of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8247"/>
        <source>Sets the minimum width of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8248"/>
        <source>Causes an element to be removed from the flow and reinserted at a later point in the document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8249"/>
        <source>Specifies where to navigate when using the arrow-down navigation key</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8250"/>
        <source>Specifies the tabbing order for an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8251"/>
        <source>Specifies where to navigate when using the arrow-left navigation key</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8252"/>
        <source>Specifies where to navigate when using the arrow-right navigation key</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8253"/>
        <source>Specifies where to navigate when using the arrow-up navigation key</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8254"/>
        <source>Sets the opacity level for an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8255"/>
        <source>Sets the minimum number of lines that must be left at the bottom of a page when a page break occurs inside an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8256"/>
        <source>Sets all the outline properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8257"/>
        <source>Sets the color of an outline</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8258"/>
        <source>Offsets an outline, and draws it beyond the border edge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8259"/>
        <source>Sets the style of an outline</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8260"/>
        <source>Sets the width of an outline</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8261"/>
        <source>Specifies what happens if content overflows an element&apos;s box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8262"/>
        <source>Specifies the preferred scrolling method for elements that overflow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8263"/>
        <source>Specifies whether or not to clip the left/right edges of the content, if it overflows the element&apos;s content area</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8264"/>
        <source>Specifies whether or not to clip the top/bottom edges of the content, if it overflows the element&apos;s content area</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8265"/>
        <source>Sets all the padding properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8266"/>
        <source>Sets the bottom padding of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8267"/>
        <source>Sets the left padding of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8268"/>
        <source>Sets the right padding of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8269"/>
        <source>Sets the top padding of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8270"/>
        <source>Specifies a particular type of page where an element SHOULD be displayed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8271"/>
        <source>Sets the page-breaking behavior after an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8272"/>
        <source>Sets the page-breaking behavior before an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8273"/>
        <source>Sets the page-breaking behavior inside an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8274"/>
        <source>Determines which page-based occurance of a given element is applied to a counter or string value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8275"/>
        <source>Specifies the perspective on how 3D elements are viewed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8276"/>
        <source>Specifies the bottom position of 3D elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8277"/>
        <source>Specifies a phonetic pronunciation for the text contained by the corresponding element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8278"/>
        <source>Specifies the type of positioning method used for an element (static, relative, absolute or fixed)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8279"/>
        <source>Specifies whether a punctuation character should be trimmed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8280"/>
        <source>Sets the type of quotation marks for embedded quotations</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8281"/>
        <source>Permits the specification of a color profile rendering intent other than the default</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8282"/>
        <source>Specifies whether or not an element is resizable by the user</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8283"/>
        <source>A shorthand property for setting the rest-before and rest-after properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8284"/>
        <source>Specifies a rest or prosodic boundary to be observed after speaking an element&apos;s content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8285"/>
        <source>Specifies a rest or prosodic boundary to be observed before speaking an element&apos;s content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8286"/>
        <source>Specifies the right position of a positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8287"/>
        <source>Rotates an element around a given point defined by the rotation-point property</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8288"/>
        <source>Defines a point as an offset from the top left border edge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8289"/>
        <source>Controls the text alignment of the ruby text and ruby base contents relative to each other</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8290"/>
        <source>Determines whether, and on which side, ruby text is allowed to partially overhang any adjacent text in addition to its own base, when the ruby text is wider than the ruby base</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8291"/>
        <source>Controls the position of the ruby text with respect to its base</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8292"/>
        <source>Controls the spanning behavior of annotation elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8293"/>
        <source>Specifies the size and orientation of the containing box for page content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8295"/>
        <source>Sets the layout algorithm to be used for a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8296"/>
        <source>A shorthand property for setting the target-name, target-new, and target-position properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8297"/>
        <source>Specifies where to open links (target destination)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8298"/>
        <source>Specifies whether new destination links should open in a new window or in a new tab of an existing window</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8299"/>
        <source>Specifies where new destination links should be placed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8300"/>
        <source>Specifies the horizontal alignment of text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8301"/>
        <source>Describes how the last line of a block or a line right before a forced line break is aligned when text-align is &apos;justify&apos;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8302"/>
        <source>Specifies the decoration added to text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8303"/>
        <source>Sets the block-progression dimension of the text content area of an inline box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8304"/>
        <source>Specifies the indentation of the first line in a text-block</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8305"/>
        <source>Specifies the justification method used when text-align is &apos;justify&apos;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8306"/>
        <source>Specifies a text outline</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8307"/>
        <source>Specifies what should happen when text overflows the containing element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8308"/>
        <source>Adds shadow to text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8309"/>
        <source>Controls the capitalization of text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8310"/>
        <source>Specifies line breaking rules for text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8311"/>
        <source>Specifies the top position of a positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8312"/>
        <source>Applies a 2D or 3D transformation to an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8313"/>
        <source>Allows you to change the position on transformed elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8314"/>
        <source>Specifies how nested elements are rendered in 3D space</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8315"/>
        <source>A shorthand property for setting the four transition properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8316"/>
        <source>Specifies when the transition effect will start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8317"/>
        <source>Specifies how many seconds or milliseconds a transition effect takes to complete</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8318"/>
        <source>Specifies the name of the CSS property the transition effect is for</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8319"/>
        <source>Specifies the speed curve of the transition effect</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8321"/>
        <source>Sets the vertical alignment of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8322"/>
        <source>Specifies whether or not an element is visible</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8323"/>
        <source>Specifies the balance between left and right channels</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8324"/>
        <source>Specifies how long it should take to render the selected element&apos;s content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8325"/>
        <source>Specifies the average pitch (a frequency) of the speaking voice</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8326"/>
        <source>Specifies variation in average pitch</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8327"/>
        <source>Controls the speaking rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8328"/>
        <source>Indicates the strength of emphasis to be applied</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8329"/>
        <source>Refers to the amplitude of the waveform output by the speech synthesises</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8330"/>
        <source>Specifies how white-space inside an element is handled</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8331"/>
        <source>Sets the minimum number of lines that must be left at the top of a page when a page break occurs inside an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8332"/>
        <source>Sets the width of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8333"/>
        <source>Specifies line breaking rules for non-CJK scripts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8334"/>
        <source>Increases or decreases the space between words in a text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8335"/>
        <source>Allows long, unbreakable words to be broken and wrap to the next line</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8336"/>
        <source>Sets the stack order of a positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8779"/>
        <source>Defines the document type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8780"/>
        <source>Defines a hyperlink</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8781"/>
        <source>Defines an abbreviation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8782"/>
        <source>Not supported in HTML5. Defines an acronym</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8783"/>
        <source>Defines contact information for the author/owner of a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8784"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Defines an embedded applet</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8785"/>
        <source>Defines an area inside an image-map</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8786"/>
        <source>Defines an article</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8787"/>
        <source>Defines content aside from the page content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8788"/>
        <source>Defines sound content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8789"/>
        <source>Defines bold text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8790"/>
        <source>Specifies the base URL/target for all relative URLs in a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8791"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Specifies a default color, size, and font for all text in a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8792"/>
        <source>Isolates a part of text that might be formatted in a different direction from other text outside it</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8793"/>
        <source>Overrides the current text direction</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8794"/>
        <source>Not supported in HTML5. Defines big text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8795"/>
        <source>Defines a section that is quoted from another source</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8796"/>
        <source>Defines the document&apos;s body</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8797"/>
        <source>Defines a single line break</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8798"/>
        <source>Defines a clickable button</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8799"/>
        <source>Used to draw graphics, on the fly, via scripting (usually JavaScript)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8800"/>
        <source>Defines a table caption</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8801"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Defines centered text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8802"/>
        <source>Defines the title of a work</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8803"/>
        <source>Defines a piece of computer code</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8804"/>
        <source>Specifies column properties for each column within a &lt;colgroup&gt; element </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8805"/>
        <source>Specifies a group of one or more columns in a table for formatting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8806"/>
        <source>Defines a command button that a user can invoke</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8807"/>
        <source>Specifies a list of pre-defined options for input controls</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8808"/>
        <source>Defines a description of an item in a definition list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8809"/>
        <source>Defines text that has been deleted from a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8810"/>
        <source>Defines additional details that the user can view or hide</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8811"/>
        <source>Defines a definition term</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8812"/>
        <source>Defines a dialog box or window</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8813"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Defines a directory list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8814"/>
        <location filename="../staticfunctions.cpp" line="8874"/>
        <location filename="../staticfunctions.cpp" line="8878"/>
        <source>Defines a section in a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8815"/>
        <source>Defines a definition list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8816"/>
        <source>Defines a term (an item) in a definition list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8817"/>
        <source>Defines emphasized text </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8818"/>
        <source>Defines a container for an external (non-HTML) application</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8819"/>
        <source>Groups related elements in a form</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8820"/>
        <source>Defines a caption for a &lt;figure&gt; element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8821"/>
        <source>Specifies self-contained content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8822"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Defines font, color, and size for text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8823"/>
        <source>Defines a footer for a document or section</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8824"/>
        <source>Defines an HTML form for user input</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8825"/>
        <source>Not supported in HTML5. Defines a window (a frame) in a frameset</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8826"/>
        <source>Not supported in HTML5. Defines a set of frames</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8827"/>
        <location filename="../staticfunctions.cpp" line="8828"/>
        <location filename="../staticfunctions.cpp" line="8829"/>
        <location filename="../staticfunctions.cpp" line="8830"/>
        <location filename="../staticfunctions.cpp" line="8831"/>
        <location filename="../staticfunctions.cpp" line="8832"/>
        <location filename="../staticfunctions.cpp" line="8833"/>
        <source>Defines HTML headings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8834"/>
        <source>Defines information about the document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8835"/>
        <source>Defines a header for a document or section</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8836"/>
        <source>Groups heading (&lt;h1&gt; to &lt;h6&gt;) elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8837"/>
        <source>Defines a thematic change in the content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8838"/>
        <source>Defines the root of an HTML document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8839"/>
        <source>Defines a part of text in an alternate voice or mood</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8840"/>
        <source>Defines an inline frame</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8841"/>
        <source>Defines an image</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8842"/>
        <source>Defines an input control</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8843"/>
        <source>Defines a text that has been inserted into a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8844"/>
        <source>Defines keyboard input</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8845"/>
        <source>Defines a key-pair generator field (for forms)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8846"/>
        <source>Defines a label for an &lt;input&gt; element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8847"/>
        <source>Defines a caption for a &lt;fieldset&gt;, &lt; figure&gt;, or &lt;details&gt; element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8848"/>
        <source>Defines a list item</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8849"/>
        <source>Defines the relationship between a document and an external resource (most used to link to style sheets)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8850"/>
        <source>Defines a client-side image-map</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8851"/>
        <source>Defines marked/highlighted text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8852"/>
        <source>Defines a list/menu of commands</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8853"/>
        <source>Defines metadata about an HTML document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8854"/>
        <source>Defines a scalar measurement within a known range (a gauge)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8855"/>
        <source>Defines navigation links</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8856"/>
        <source>Not supported in HTML5. Defines an alternate content for users that do not support frames</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8857"/>
        <source>Defines an alternate content for users that do not support client-side scripts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8858"/>
        <source>Defines an embedded object</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8859"/>
        <source>Defines an ordered list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8860"/>
        <source>Defines a group of related options in a drop-down list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8861"/>
        <source>Defines an option in a drop-down list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8862"/>
        <source>Defines the result of a calculation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8863"/>
        <source>Defines a paragraph</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8864"/>
        <source>Defines a parameter for an object</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8865"/>
        <source>Defines preformatted text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8866"/>
        <source>Represents the progress of a task</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8867"/>
        <source>Defines a short quotation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8868"/>
        <source>Defines what to show in browsers that do not support ruby annotations</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8869"/>
        <source>Defines an explanation/pronunciation of characters (for East Asian typography)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8870"/>
        <source>Defines a ruby annotation (for East Asian typography)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8871"/>
        <source>Defines text that is no longer correct</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8872"/>
        <source>Defines sample output from a computer program</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8873"/>
        <source>Defines a client-side script</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8875"/>
        <source>Defines a drop-down list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8876"/>
        <source>Defines smaller text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8877"/>
        <source>Defines multiple media resources for media elements (&lt;video&gt; and &lt;audio&gt;)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8879"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Defines strikethrough text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8880"/>
        <source>Defines important text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8881"/>
        <source>Defines style information for a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8882"/>
        <source>Defines subscripted text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8883"/>
        <source>Defines a visible heading for a &lt;details&gt; element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8884"/>
        <source>Defines superscripted text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8885"/>
        <source>Defines a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8886"/>
        <source>Groups the body content in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8887"/>
        <source>Defines a cell in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8888"/>
        <source>Defines a multiline input control (text area)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8889"/>
        <source>Groups the footer content in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8890"/>
        <source>Defines a header cell in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8891"/>
        <source>Groups the header content in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8892"/>
        <source>Defines a date/time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8893"/>
        <source>Defines a title for the document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8894"/>
        <source>Defines a row in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8895"/>
        <source>Defines text tracks for media elements (&lt;video&gt; and &lt;audio&gt;)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8896"/>
        <source>Not supported in HTML5. Defines teletype text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8897"/>
        <source>Defines text that should be stylistically different from normal text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8898"/>
        <source>Defines an unordered list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8899"/>
        <source>Defines a variable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8900"/>
        <source>Defines a video or movie</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8901"/>
        <source>Defines a possible line-break</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9005"/>
        <source>Uptime in days</source>
        <translation type="unfinished">Tiempo encendido en días</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9005"/>
        <source>Variable</source>
        <translation type="unfinished">Variable</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9005"/>
        <source>Value</source>
        <translation type="unfinished">Valor</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9005"/>
        <source>The number of days that the server has been up.</source>
        <translation type="unfinished">El número de días que el servidor ha estado en funcionamiento.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9005"/>
        <source>Description</source>
        <translation type="unfinished">Descripción</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9007"/>
        <source>Aborted clients</source>
        <translation type="unfinished">Clientes abortados</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9007"/>
        <source>The number of connections that were aborted because the client died without closing the connection properly.</source>
        <translation type="unfinished">El número de conexiones que han sido abortadas debido a que el cliente murió sin cerrar la conexión correctamente.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9009"/>
        <source>Aborted clients per day</source>
        <translation type="unfinished">Clientes abortados por día</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9012"/>
        <source>Rate of aborted clients per day.</source>
        <translation type="unfinished">Tasa de clientes abortados por día.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9014"/>
        <source>Aborted connections</source>
        <translation type="unfinished">Conexiones abortadas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9014"/>
        <source>The number of failed attempts to connect to the database server.</source>
        <translation type="unfinished">El número de intentos fallidos de conectarse al servidor de base de datos.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9016"/>
        <source>Executed rollbacks</source>
        <translation type="unfinished">Rollbacks ejecutados</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9016"/>
        <source>The number of times each rollback statement has been executed.</source>
        <translation type="unfinished">El número de veces que cada sentencia de rollback se ha ejecutado.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9018"/>
        <source>Executed queries</source>
        <translation type="unfinished">Consultas ejecutadas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9018"/>
        <source>The number of statements executed by the server.</source>
        <translation type="unfinished">El número de sentencias ejecutadas por el servidor.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9020"/>
        <source>Rollbacks per second</source>
        <translation type="unfinished">Rollbacks por segundo</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9023"/>
        <source>Rate of rollbacks per second.</source>
        <translation type="unfinished">Tasa de rollbacks por segundo.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9025"/>
        <source>Temporary disk tables created</source>
        <translation type="unfinished">Tablas temporales de disco creadas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9025"/>
        <source>The number of internal on-disk temporary tables created by the server while executing statements.</source>
        <translation type="unfinished">El número de tablas temporales en disco internas creadas por el servidor mientras ejecuta las sentencias.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9027"/>
        <source>Free cache memory</source>
        <translation type="unfinished">Memoria cache libre</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9027"/>
        <source>The amount of free memory for the query cache.</source>
        <translation type="unfinished">La cantidad de memoria libre para la caché de consultas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9029"/>
        <source>Joins with full table scan</source>
        <translation type="unfinished">Joins con escaneo completo de tabla</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9029"/>
        <source>The number of joins that perform table scans because they do not use indexes.</source>
        <translation type="unfinished">El número de joins que realizan escaneos de tablas porque que no utilizan índices.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9031"/>
        <source>Log slow queries</source>
        <translation type="unfinished">Guardar consultas lentas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9031"/>
        <source>Is the slow queries logging enabled?</source>
        <translation type="unfinished">¿Está el loggeo de consultas habilitado?</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9033"/>
        <source>Slow queries time in seconds</source>
        <translation type="unfinished">Tiempo de consultas lentas en segundos</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9033"/>
        <source>The number of seconds that determinate a slow query.</source>
        <translation type="unfinished">El número de segundos para determinar que una consulta es lenta.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9035"/>
        <source>Count of slow queries</source>
        <translation type="unfinished">Conteo de consultas lentas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9035"/>
        <source>The number of queries that have taken more than the allowed time.</source>
        <translation type="unfinished">El número de consultas que han tardado más que el tiempo permitido.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9037"/>
        <source>Idle connections</source>
        <translation type="unfinished">Conexiones inactivas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9037"/>
        <source>The number of connections that has been idle for more than 30 seconds.</source>
        <translation type="unfinished">El número de conexiones que ha estado inactivo durante más de 30 segundos.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9039"/>
        <source>Active connections</source>
        <translation>Conexiones activas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9039"/>
        <source>The number of connections that has been idle for less than 30 seconds.</source>
        <translation>El número de conexiones que ha estado inactivo durante menos de 30 segundos.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9041"/>
        <source>Total connections</source>
        <translation>Toral de conexiones</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9041"/>
        <source>The number of active connections on the server.</source>
        <translation>El número de conexiones activas en el servidor.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9043"/>
        <source>Max connections aviable</source>
        <translation type="unfinished">Cantidad máxima de conexiones disponibles</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9043"/>
        <source>The maximum permitted number of simultaneous client connections.</source>
        <translation type="unfinished">El número máximo permitido de conexiones de cliente simultáneas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9045"/>
        <source>Used connections</source>
        <translation type="unfinished">Conexiones usadas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9045"/>
        <source>The maximum number of connections that have been in use simultaneously since the server started.</source>
        <translation type="unfinished">El número máximo de conexiones que han sido utilizadas simultáneamente desde que el servidor se inició.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9061"/>
        <source>Date</source>
        <translation type="unfinished">Fecha</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9061"/>
        <source>Day</source>
        <translation type="unfinished">Día</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9061"/>
        <source>Total queries</source>
        <translation type="unfinished">Total de consultas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="9062"/>
        <source>Average (in seconds)</source>
        <translation type="unfinished">Promedio (en segundos)</translation>
    </message>
    <message>
        <source>Slow queries since server started.</source>
        <translation type="obsolete">Consultas lentas desde que el servidor inició.</translation>
    </message>
</context>
<context>
    <name>SubversionedFile</name>
    <message>
        <location filename="../subversionedfile.cpp" line="36"/>
        <source>Diff</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../subversionedfile.cpp" line="38"/>
        <source>Commit</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../subversionedfile.cpp" line="40"/>
        <source>Revert</source>
        <translation>Revertir</translation>
    </message>
    <message>
        <location filename="../subversionedfile.cpp" line="42"/>
        <source>Info</source>
        <translation>Info</translation>
    </message>
    <message>
        <location filename="../subversionedfile.cpp" line="44"/>
        <source>Status</source>
        <translation>Estado</translation>
    </message>
    <message>
        <location filename="../subversionedfile.cpp" line="46"/>
        <source>Update</source>
        <translation>Actualizar</translation>
    </message>
    <message>
        <location filename="../subversionedfile.cpp" line="48"/>
        <source>Add</source>
        <translation>Agregar</translation>
    </message>
    <message>
        <location filename="../subversionedfile.cpp" line="50"/>
        <source>Delete</source>
        <translation>Borrar</translation>
    </message>
    <message>
        <location filename="../subversionedfile.cpp" line="52"/>
        <source>Log</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../subversionedfile.cpp" line="71"/>
        <source>Version control</source>
        <translation>Control de versiones</translation>
    </message>
    <message>
        <location filename="../subversionedfile.cpp" line="71"/>
        <source>This is not a versioned file.</source>
        <translation>Este no es un archivo versionado.</translation>
    </message>
</context>
<context>
    <name>TableMaintenance</name>
    <message>
        <location filename="../tablemaintenance.cpp" line="105"/>
        <source>Table Maintenance</source>
        <translation>Mantenimiento de Tablas</translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="108"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="109"/>
        <source>Analyze</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="110"/>
        <source>Check</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="111"/>
        <source>Checksum</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="112"/>
        <source>Optimize</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="113"/>
        <source>Repair</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="114"/>
        <source>Databases</source>
        <translation>Bases de Datos</translation>
    </message>
</context>
<context>
    <name>TextEditor</name>
    <message>
        <location filename="../texteditor.cpp" line="236"/>
        <source>Recent files</source>
        <translation>Archivos recientes</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="237"/>
        <location filename="../texteditor.cpp" line="248"/>
        <source>Symbols</source>
        <translation>Símbolos</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="499"/>
        <source>Print Script</source>
        <translation>Imprimir Script</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="537"/>
        <source>Clean</source>
        <translation>Limpiar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="957"/>
        <location filename="../texteditor.cpp" line="961"/>
        <source>Save file</source>
        <translation>Guardar archivo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="957"/>
        <source>Cannot save empty files.</source>
        <translation>No es posible guardar archivos en blanco.</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="269"/>
        <source>Cut line</source>
        <translation>Cortar línea</translation>
    </message>
    <message>
        <source>Explain SELECT</source>
        <translation type="obsolete">Explicar SELECT</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="300"/>
        <source>Show SQL Helpers in the completion</source>
        <translation>Mostar Ayudas de SQL en el completado</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="302"/>
        <source>Export to Pdf</source>
        <translation>Exportar a Pdf</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="303"/>
        <source>Export to Odt</source>
        <translation>Exportar a Odt</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="304"/>
        <source>Export to Html</source>
        <translation>Exportar a Html</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="305"/>
        <source>Export to Svg</source>
        <translation>Exportar a Svg</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="306"/>
        <source>Export to Image</source>
        <translation>Exportar a Imagen</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="307"/>
        <source>Toggle Comment</source>
        <translation>Intercambiar Comentarios</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="316"/>
        <source>Uppercase keywords</source>
        <translation>Hacer mayúsculas las palabras clave</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="317"/>
        <source>Lowercase keywords</source>
        <translation>Hacer minúsculas las palabras clave</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1265"/>
        <source>SQL Query: Save file...</source>
        <translation>Consulta SQL: Guardar archivo...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1268"/>
        <source>PHP Script: Save file...</source>
        <translation>Script PHP: Guardar archivo...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1271"/>
        <source>CSS File: Save file...</source>
        <translation>Archivo CSS: Guardar archivo...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1274"/>
        <source>HTML File: Save file...</source>
        <translation>Archivo HTML: Guardar archivo...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1277"/>
        <source>JavaScript Script: Save file...</source>
        <translation>Script JavaScript: Guardar archivo...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1471"/>
        <source>PHP files (*.php *.inc *.module)</source>
        <translation>Archivos PHP (*.php *.inc *.module)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="971"/>
        <location filename="../texteditor.cpp" line="1840"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="240"/>
        <source>Edit Menu</source>
        <translation>Menú Editar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="241"/>
        <source>&amp;Export</source>
        <translation>&amp;Exportar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="238"/>
        <source>Sort by name</source>
        <translation>Ordenar por nombre</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="986"/>
        <location filename="../texteditor.cpp" line="1815"/>
        <location filename="../texteditor.cpp" line="1828"/>
        <location filename="../texteditor.cpp" line="1846"/>
        <location filename="../texteditor.cpp" line="1865"/>
        <location filename="../texteditor.cpp" line="1888"/>
        <source>File saved at: %1</source>
        <translation>Archivo guardado en: %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="249"/>
        <source>Clear</source>
        <translation>Limpiar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="250"/>
        <source>Open</source>
        <translation>Abrir</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="251"/>
        <source>Save</source>
        <translation>Guardar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="252"/>
        <source>Save as...</source>
        <translation>Guardar como...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="253"/>
        <source>Copy</source>
        <translation>Copiar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="254"/>
        <source>Cut</source>
        <translation>Cortar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="255"/>
        <source>Paste</source>
        <translation>Pegar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="256"/>
        <source>Undo</source>
        <translation>Deshacer</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="257"/>
        <source>Redo</source>
        <translation>Rehacer</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="258"/>
        <source>Word wrap</source>
        <translation>Ajuste de línea</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="259"/>
        <source>In</source>
        <translation>Acercar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="260"/>
        <source>Out</source>
        <translation>Aleajr</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="261"/>
        <source>Restore</source>
        <translation>Restaurar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="262"/>
        <source>Line...</source>
        <translation>Línea...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="263"/>
        <source>Select all</source>
        <translation>Seleccionar todo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="264"/>
        <source>Clear recent files</source>
        <translation>Limpiar archivos recientes</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="265"/>
        <source>Print...</source>
        <translation>Imprimir...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="266"/>
        <source>Reload file</source>
        <translation>Recargar archivo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="267"/>
        <source>Disable completion</source>
        <translation>Deshabilitar completado</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="268"/>
        <source>Show/Hide line numbers</source>
        <translation>Mostrar/Ocultar números de línea</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="273"/>
        <source>SQL Query %1</source>
        <translation>Consulta SQL %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="274"/>
        <source>Fill MariaDB Symbols</source>
        <translation>Llenar símbolos de MariaDB</translation>
    </message>
    <message>
        <source>Explain INSERT</source>
        <translation type="obsolete">Explicar INSERT</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="277"/>
        <source>Run PHP Script</source>
        <translation>Correr Script PHP</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="278"/>
        <source>PHP Script %1</source>
        <translation>Script PHP %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="281"/>
        <source>CSS Script %1</source>
        <translation>Script CSS %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="284"/>
        <source>HTML Script %1</source>
        <translation>Script HTML %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="287"/>
        <source>JavaScript Script %1</source>
        <translation>Script JavaScript %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="290"/>
        <source>Text File %1</source>
        <translation>Archivo de Texto %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="308"/>
        <source>Highlight current line</source>
        <translation>Resaltar la línea actual</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="309"/>
        <source>Normal</source>
        <translation>Normal</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="310"/>
        <source>Vertical</source>
        <translation>Vertical</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="311"/>
        <source>Horizontal</source>
        <translation>Horizontal</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="312"/>
        <source>&amp;Show Symols</source>
        <translation>&amp;Mostrar Símbolos</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="313"/>
        <source>&amp;Normalize text</source>
        <translation>&amp;Normalizar texto</translation>
    </message>
    <message>
        <source>Insert licence template</source>
        <translation type="obsolete">Insertar plantilla de licencia</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1468"/>
        <source>SQL files (*.sql)</source>
        <translation>Archivos SQL (*.sql)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1521"/>
        <source>Zoom</source>
        <translation>Enfocar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1808"/>
        <source>Save to Pdf</source>
        <translation>Guardar en Pdf</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1808"/>
        <source>Pdf &amp; Ps files (*.pdf *.ps)</source>
        <translation>Archivos Pdf &amp; Ps (*.pdf *.ps)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1823"/>
        <source>Save to Odt</source>
        <translation>Guardar en Odt</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1823"/>
        <source>Odt files (*.odt)</source>
        <translation>Archivos Odt (*.odt)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1836"/>
        <source>Save to Html</source>
        <translation>Guardar en Html</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1836"/>
        <source>Html files (*.html *.htm)</source>
        <translation>Archivos Html (*.html *.htm)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1854"/>
        <source>Save to Svg</source>
        <translation>Guardar en Svg</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1854"/>
        <source>Svg files (*.svg)</source>
        <translation>Archivos Svg (*.svg)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1876"/>
        <source>Save to Image</source>
        <translation>Guardar en Imagen</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1876"/>
        <source>Image files (%1)</source>
        <translation>Archivos de imagen (%1)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="242"/>
        <source>&amp;File</source>
        <translation>&amp;Archivo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="243"/>
        <source>&amp;Edit</source>
        <translation>&amp;Editar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="244"/>
        <source>&amp;Options</source>
        <translation>&amp;Opciones</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="245"/>
        <source>&amp;Subversion</source>
        <translation>&amp;Subversion</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="246"/>
        <source>&amp;View</source>
        <translation>&amp;Ver</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="247"/>
        <source>View</source>
        <translation>Ver</translation>
    </message>
    <message>
        <source>Tool bar</source>
        <translation type="obsolete">Barra de herramientas</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1287"/>
        <source>The document has been modified.</source>
        <translation>El documento ha sido modificado.</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1288"/>
        <source>Do you want to save the changes?</source>
        <translation>¿Desea guardar los cambios?</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1364"/>
        <source>Go To Line...</source>
        <translation>Ir a la Línea...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1364"/>
        <source>Line number</source>
        <translation>Número de línea</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1474"/>
        <source>CSS files (*.css)</source>
        <translation>Archivos CSS (*.css)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1477"/>
        <source>HTML files (*.html *.htm)</source>
        <translation>Archivos HTML (*.html *.htm)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1480"/>
        <source>JavaScript files (*.js)</source>
        <translation>Archivos JavaScript (*.js)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1494"/>
        <source>Open a file</source>
        <translation>Abrir un archivo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1502"/>
        <source>Cannot read file %1:
%2.</source>
        <translation>No es posible leer el archivo %1: %2.</translation>
    </message>
</context>
<context>
    <name>Users</name>
    <message>
        <location filename="../users.cpp" line="109"/>
        <source>User Administration</source>
        <translation>Administración de Usuarios</translation>
    </message>
    <message>
        <location filename="../users.cpp" line="112"/>
        <source>Login informaction</source>
        <translation>Información de inicio de sesión</translation>
    </message>
    <message>
        <location filename="../users.cpp" line="114"/>
        <source>Username:</source>
        <translation>Nombre de usuario:</translation>
    </message>
    <message>
        <location filename="../users.cpp" line="116"/>
        <source>Password:</source>
        <translation>Contraseña:</translation>
    </message>
    <message>
        <source>Event</source>
        <translation type="obsolete">Evento</translation>
    </message>
</context>
</TS>
