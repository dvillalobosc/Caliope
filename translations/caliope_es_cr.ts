<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="es_CR" sourcelanguage="en">
<context>
    <name>Backup</name>
    <message>
        <location filename="../backup.cpp" line="104"/>
        <source>Backup</source>
        <translation>Respaldo</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="107"/>
        <source>Note that there are options that exclude others.</source>
        <translation>Note que hay opciones que excluyen a otras.</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="81"/>
        <source>Cannot backup this kind of database</source>
        <translation>No es posible respaladar este tipo de base de datos</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="108"/>
        <source>&amp;File:</source>
        <translation>&amp;Archivo:</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="109"/>
        <source>Create Backup</source>
        <translation>Crear Respaldo</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="178"/>
        <source>Backup done.</source>
        <translation>Respaldo realizado.</translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="194"/>
        <source>Add a DROP DATABASE statement before each CREATE DATABASE statement</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="201"/>
        <source>Add a DROP TABLE statement before each CREATE TABLE statement</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="205"/>
        <source>Add a DROP TRIGGER statement before each CREATE TRIGGER statement</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="209"/>
        <source>Surround each table dump with LOCK TABLES and UNLOCK TABLES statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="213"/>
        <source>Backup all databases</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="218"/>
        <source>Adds to a table dump all SQL statements needed to create any tablespaces used by an NDB Cluster table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="222"/>
        <source>Allow creation of column names that are keywords</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="228"/>
        <source>Add comments to the dump file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="232"/>
        <source>Produce more compact output</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="238"/>
        <source>Use complete INSERT statements that include column names</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="242"/>
        <source>Include all MySQL-specific table options in CREATE TABLE statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="251"/>
        <source>Write INSERT DELAYED statements rather than INSERT statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="255"/>
        <source>On a master replication server, delete the binary logs after performing the dump operation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="259"/>
        <source>For each table, surround the INSERT statements with statements to disable and enable keys</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="263"/>
        <source>Include dump date as &apos;Dump completed on&apos; comment if --comments is given</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="267"/>
        <source>Dump events from the dumped databases</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="271"/>
        <source>Use multiple-row INSERT syntax that include several VALUES lists</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="282"/>
        <source>Flush the MySQL server log files before starting the dump</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="286"/>
        <source>Emit a FLUSH PRIVILEGES statement after dumping the mysql database</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="292"/>
        <source>Dump binary columns using hexadecimal notation (for example, &apos;abc&apos; becomes 0x616263)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="299"/>
        <source>Write INSERT IGNORE statements rather than INSERT statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="305"/>
        <source>Lock all tables across all databases</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="309"/>
        <source>Lock all tables before dumping them</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="318"/>
        <source>Enclose the INSERT statements for each dumped table within SET autocommit = 0 and COMMIT statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="322"/>
        <source>This option suppresses the CREATE DATABASE statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="326"/>
        <source>Do not write CREATE TABLE statements that re-create each dumped table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="330"/>
        <source>Do not dump table contents</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="334"/>
        <source>Same as --skip-set-charset</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="338"/>
        <source>Do not write any CREATE LOGFILE GROUP or CREATE TABLESPACE statements in output</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="342"/>
        <source>Shorthand for --add-drop-table --add-locks --create-options --disable-keys --extended-insert --lock-tables --quick --set-charset.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="346"/>
        <source>Dump each table&apos;s rows sorted by its primary key, or by its first unique index</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="352"/>
        <source>Retrieve rows for a table from the server a row at a time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="356"/>
        <source>Quote identifiers within backtick characters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="361"/>
        <source>Write REPLACE statements rather than INSERT statements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="365"/>
        <source>Dump stored routines (procedures and functions) from the dumped databases</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="371"/>
        <source>This option issues a BEGIN SQL statement before dumping data from the server</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="375"/>
        <source>Do not add a DROP TABLE statement before each CREATE TABLE statement</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="380"/>
        <location filename="../backup.cpp" line="385"/>
        <source>Do not add comments to the dump file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="390"/>
        <source>Do not produce more compact output</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="395"/>
        <source>Do not disable keys</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="400"/>
        <source>Turn off extended-insert</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="405"/>
        <source>Turn off the options set by --opt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="410"/>
        <source>Do not retrieve rows for a table from the server a row at a time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="415"/>
        <source>Do not quote identifiers</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="420"/>
        <source>Suppress the SET NAMES statement</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="425"/>
        <source>Do not dump triggers</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="430"/>
        <source>Turn off tz-utc</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="446"/>
        <source>Dump triggers for each dumped table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="450"/>
        <source>Add SET TIME_ZONE=&apos;+00:00&apos; to the dump file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="454"/>
        <source>Verbose mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../backup.cpp" line="461"/>
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
        <location filename="../basetexteditor.cpp" line="418"/>
        <source>Indent</source>
        <translation>Indentar</translation>
    </message>
    <message>
        <location filename="../basetexteditor.cpp" line="420"/>
        <source>Unindent</source>
        <translation>Desindentar</translation>
    </message>
    <message>
        <location filename="../basetexteditor.cpp" line="422"/>
        <source>Insert licence template</source>
        <translation>Insertar plantilla de licencia</translation>
    </message>
    <message>
        <location filename="../basetexteditor.cpp" line="424"/>
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
        <location filename="../catalogs.cpp" line="445"/>
        <source>Rows to be inserted</source>
        <translation>Filas a ser insertadas</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="446"/>
        <location filename="../catalogs.cpp" line="467"/>
        <source>Inserting records...</source>
        <translation>Insertando filas...</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="469"/>
        <source>Records inserted.</source>
        <translation>Registros insertados.</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="478"/>
        <source>New table</source>
        <translation>Nueva tabla</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="481"/>
        <source>New view</source>
        <translation>Nueva vista</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="484"/>
        <source>New index</source>
        <translation>Nuevo índice</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="487"/>
        <source>New field</source>
        <translation>Nuevo campo</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="490"/>
        <source>New routine</source>
        <translation>Nueva rutina</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="493"/>
        <source>New trigger</source>
        <translation>Nuevo trigger</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="496"/>
        <source>New event</source>
        <translation>Nuevo evento</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="580"/>
        <source>Indexes on: %1</source>
        <translation>Indices en: %1</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="582"/>
        <source>Fields on: %1</source>
        <translation>Campos en: %1</translation>
    </message>
    <message>
        <location filename="../catalogs.cpp" line="584"/>
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
        <location filename="../connectdialog.cpp" line="47"/>
        <source>Connect to a Database Server</source>
        <translation>Conectarse a un Servidor de Base de Datos</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="58"/>
        <source>Sort connection list by used times</source>
        <translation>Ordenar la lista de conexiones por las veces usadas</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="128"/>
        <source>Use a SSL connection</source>
        <translation>Usar conecxión SSL</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="132"/>
        <source>SSL Client Key file:</source>
        <translation>Archivo SSL Llave del cliente:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="133"/>
        <source>SSL Client Cert file:</source>
        <translation>Archivo SSL Cert del cliente:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="137"/>
        <source>&amp;Connection Name:</source>
        <translation>&amp;Nombre de la Conexión:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="139"/>
        <source>Connection &amp;Type:</source>
        <translation>&amp;Tipo de Conexión:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="140"/>
        <source>&amp;Server:</source>
        <translation>&amp;Servidor:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="141"/>
        <source>&amp;Port:</source>
        <translation>&amp;Puerto:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="142"/>
        <source>&amp;User:</source>
        <translation>&amp;Usuario:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="143"/>
        <source>Password:</source>
        <translation>Contraseña:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="154"/>
        <location filename="../connectdialog.cpp" line="293"/>
        <source>Ping</source>
        <translation>Pint</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="155"/>
        <location filename="../connectdialog.cpp" line="310"/>
        <source>New connection</source>
        <translation>Nueva conexión</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="309"/>
        <source>Ping successful to: %1</source>
        <translation>Ping exitoso a: %1</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="309"/>
        <source>Ping successful</source>
        <translation>Ping exitoso</translation>
    </message>
    <message>
        <source>&amp;Password:</source>
        <translation type="obsolete">&amp;Contraseña:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="144"/>
        <source>Database:</source>
        <translation>Base de Datos:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="145"/>
        <source>Collation:</source>
        <translation>Cotejo:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="112"/>
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
        <location filename="../dbms.cpp" line="239"/>
        <location filename="../dbms.cpp" line="240"/>
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
        <source>Rows in set: %1</source>
        <translation type="obsolete">Filas en el resultado: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="419"/>
        <location filename="../dbms.cpp" line="482"/>
        <source>Undefined Database driver.</source>
        <translation>Controlador de Base de datos indefinido.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="498"/>
        <source>Error:</source>
        <translation>Error:</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="506"/>
        <location filename="../dbms.cpp" line="1523"/>
        <source>No error code provided.</source>
        <translation>No hay código de error proporcionado.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="615"/>
        <source>Select a file</source>
        <translation>Seleccione un archivo</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="624"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="628"/>
        <source>Data exported to %1</source>
        <translation>Datos exportados a %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="58"/>
        <source>Error</source>
        <translation>Error</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="55"/>
        <source>Count</source>
        <translation>Contador</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="55"/>
        <location filename="../dbms.cpp" line="1121"/>
        <source>Query</source>
        <translation>Consulta</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="55"/>
        <source>Error message</source>
        <translation>Mensaje de error</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="67"/>
        <source>Cannot open database</source>
        <translation>No es posible abrir la base de datos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="67"/>
        <source>Unable to establish a database connection.</source>
        <translation>Imposible establecer una conexión con la base de datos.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="136"/>
        <source>MySQL Version</source>
        <translation>Versión de MySQL</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="136"/>
        <source>Your version of MySQL seems to be less than 5.1.</source>
        <translation>Su versión de MySQL parece ser mejor a 5.1.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="159"/>
        <source>Stage: %1 of %2 &apos;%3&apos;. %4% of stage done.
Total progess: %5.</source>
        <translation>Etapa: %1 de %2 &apos;%3&apos;. %4% de la etapa realizado.\nProgreso total: %5.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="176"/>
        <source>%1 milliseconds</source>
        <translation>%1 milisegundos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="178"/>
        <source>%1 seconds</source>
        <translation>%1 segundos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="180"/>
        <source>%1 minutes</source>
        <translation>%1 minutos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="182"/>
        <source>%1 hours</source>
        <translation>%1 horas</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="199"/>
        <source>Application closed</source>
        <translation>Aplicación cerrada</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="393"/>
        <location filename="../dbms.cpp" line="398"/>
        <source>Rows in set: %1. Elapsed time: %2.</source>
        <translation>Filas en el resultado: %1. Tiempo transcurrido: %2.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="408"/>
        <location filename="../dbms.cpp" line="414"/>
        <source>Rows in set: %1. Elapsed time: %2 seconds.</source>
        <translation>Filas en el resultado: %1. Tiempo transcurrido: %2.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="830"/>
        <source>Could not execute statement. </source>
        <translation>No se puede ejecutar la sentencia. </translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1102"/>
        <source>Application started</source>
        <translation>Aplicación iniciada</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1117"/>
        <source>Line Number</source>
        <translation>Número de línea</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1118"/>
        <source>Session Id</source>
        <translation>Id de Sesión</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1119"/>
        <source>Date</source>
        <translation>Fecha</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1120"/>
        <source>Connection</source>
        <translation>Conexión</translation>
    </message>
    <message>
        <source>Restarting connection</source>
        <translation type="obsolete">Reiniciando conexión</translation>
    </message>
    <message>
        <source>This acction will restart your database connection</source>
        <translation type="obsolete">Esta acción reiniciará su conexión a base de datos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1448"/>
        <source>Could not change character set to: %1</source>
        <translation>No se puede cambiar el juego de caracteres a: %1</translation>
    </message>
</context>
<context>
    <name>DBarChartWidget</name>
    <message>
        <location filename="../serverInformation.cpp" line="746"/>
        <source>Total connections in the last 60 seconds</source>
        <translation>Total de conexiones en los últimos 60 segundos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="747"/>
        <source>Kb sent by second</source>
        <translation>Kb enviados por segundo</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="748"/>
        <source>Executed queries in the last 60 seconds</source>
        <translation>Consultas ejecutadas en los últimos 60 segundos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="800"/>
        <source>Current: %1</source>
        <translation>Actual %1</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="801"/>
        <source>Max: %1</source>
        <translation>Máximo: %1</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="802"/>
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
        <location filename="../dpiechartwidget.cpp" line="88"/>
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
        <location filename="../dreportviewer.cpp" line="122"/>
        <source>Plain text</source>
        <translation>Texto plano</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="124"/>
        <source>Pie chart</source>
        <translation>Gráfico circular</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="129"/>
        <source>&amp;Report Name:</source>
        <translation>&amp;Nombre el Reporte:</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="130"/>
        <source>&amp;Unit:</source>
        <translation>&amp;Unidad:</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="131"/>
        <source>&amp;Type:</source>
        <translation>&amp;Tipo:</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="187"/>
        <source>Export to PDF</source>
        <translation>Exportar a Pdf</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="188"/>
        <source>Refresh</source>
        <translation>Refrescar</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="189"/>
        <source>Export to Image</source>
        <translation>Exportar a Imagen</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="190"/>
        <source>Export to TXT</source>
        <translation>Exportar a TXT</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="198"/>
        <source>Save to Pdf</source>
        <translation>Guardar en Pdf</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="198"/>
        <source>Pdf &amp; Ps files (*.pdf *.ps)</source>
        <translation>Archivos Pdf &amp; Ps (*.pdf *.ps)</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="205"/>
        <location filename="../dreportviewer.cpp" line="222"/>
        <location filename="../dreportviewer.cpp" line="251"/>
        <source>File saved at: %1</source>
        <translation>Archivo guardado en: %1</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="216"/>
        <source>Save to Image</source>
        <translation>Guardar en Imagen</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="216"/>
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
        <location filename="../dtableview.cpp" line="84"/>
        <location filename="../dtableview.cpp" line="106"/>
        <source>Loading records...</source>
        <translatorcomment>Registros cargados.</translatorcomment>
        <translation>Cargando registros...</translation>
    </message>
    <message>
        <location filename="../dtableview.cpp" line="118"/>
        <source>Records loaded.</source>
        <translation>Registros cargados.</translation>
    </message>
</context>
<context>
    <name>DWebView</name>
    <message>
        <location filename="../dwebview.cpp" line="86"/>
        <source>URL to load</source>
        <translation>URL a cargar</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="54"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="100"/>
        <source>Show page source</source>
        <translation>Mostrar el fuente de la página</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="101"/>
        <source>Open in external browser</source>
        <translation>Abrir en explorador externo</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="116"/>
        <location filename="../dwebview.cpp" line="134"/>
        <source>Loading page...</source>
        <translation>Cargando página...</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="122"/>
        <source>Page loaded.</source>
        <translation>Página cargada.</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="124"/>
        <source>Could not load page.</source>
        <translation>No se puede cargar la página.</translation>
    </message>
</context>
<context>
    <name>Database</name>
    <message>
        <location filename="../dbms.cpp" line="1634"/>
        <source>Database: %1</source>
        <translation>Base de Datos: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1635"/>
        <source>Total of tables: %1</source>
        <translation>Total de tablas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1636"/>
        <source>Total of views: %1</source>
        <translation>Total de vistas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1637"/>
        <source>Total of triggers: %1</source>
        <translation>Total de disparadores: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1638"/>
        <source>Total of rutines: %1</source>
        <translation>Total de rutinas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1639"/>
        <source>Total of events: %1</source>
        <translation>Total de eventos: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1640"/>
        <source>Tables size: %1</source>
        <translation>Tamaño total de las tablas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1641"/>
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
        <location filename="../databasecomparision.cpp" line="150"/>
        <source>Cannot connect to the server</source>
        <translation>No es posible conectarse al servidor</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="154"/>
        <source>Secondary database server: %1</source>
        <translation>Servidor de bases de datos secundario: %1</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="157"/>
        <source>Connected successfully to: %1</source>
        <translation>Conectado satisfactoriamente a: %1</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="189"/>
        <source>Server</source>
        <translation>Servidor</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="189"/>
        <source>Database</source>
        <translation>Base de Datos</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="189"/>
        <source>Table</source>
        <translation>Tabla</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="189"/>
        <source>Data length</source>
        <translation>Tamaño de los datos</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="189"/>
        <source>Row count</source>
        <translation>Conteo de filas</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="189"/>
        <source>Checksum</source>
        <translation>Suma de comprobación</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="190"/>
        <source>Row count validation</source>
        <translation>Validación de conteo de filas</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="191"/>
        <source>Data length validation</source>
        <translation>Validación de tamaño de los datos</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="192"/>
        <source>Checksum validation</source>
        <translation>Validación de suma de comprobación</translation>
    </message>
    <message>
        <source>Table does not exist.</source>
        <translation type="vanished">La tabla no existe.</translation>
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
        <location filename="../fileassociations.cpp" line="40"/>
        <source>SQL files:</source>
        <translation>Archivos SQL:</translation>
    </message>
    <message>
        <source>PHP files:</source>
        <translation type="vanished">Archivos PHP:</translation>
    </message>
    <message>
        <source>CSS files:</source>
        <translation type="vanished">Archivos CSS:</translation>
    </message>
    <message>
        <source>HTML files:</source>
        <translation type="vanished">Archivos HTML:</translation>
    </message>
    <message>
        <source>JavaScript files:</source>
        <translation type="vanished">Archivos JavaScript:</translation>
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
        <source>Bin files (*)</source>
        <translation type="vanished">Archivos Bin (*)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="79"/>
        <source>Image files (*.png *.jpg *.bmp)</source>
        <translation>Archivo de imagen (*.png *.jpg *.bmp)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="82"/>
        <source>PEM files (*.pem)</source>
        <translation>Archivos PEM (*.pem)</translation>
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
        <location filename="../findreplace.cpp" line="54"/>
        <source>Find next</source>
        <translation>Encontrar siguiente</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="59"/>
        <source>Find previous</source>
        <translation>Econtrar previo</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="66"/>
        <source>Replace</source>
        <translation>Remplazar</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="71"/>
        <source>Replace all</source>
        <translation>Remplazar todo</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="75"/>
        <source>Case sensitive</source>
        <translation>Sensible a mayúsculas y minúsculas</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="79"/>
        <source>Hole word</source>
        <translation>Palabra completa</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="83"/>
        <source>Regular Expression</source>
        <translation>Expresión regular</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="87"/>
        <source>Highlight all</source>
        <translation>Resaltar todo</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="130"/>
        <source>Reached the end of the document.</source>
        <translation>Llegó al final del documento.</translation>
    </message>
    <message>
        <location filename="../findreplace.cpp" line="137"/>
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
        <location filename="../mainwindow.cpp" line="184"/>
        <location filename="../mainwindow.cpp" line="1154"/>
        <location filename="../mainwindow.cpp" line="1548"/>
        <location filename="../mainwindow.cpp" line="1925"/>
        <source>Server Information</source>
        <translation>Información del Servidor</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="186"/>
        <location filename="../mainwindow.cpp" line="1551"/>
        <source>User Administration</source>
        <translation>Administración de Usuarios</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="188"/>
        <location filename="../mainwindow.cpp" line="1554"/>
        <location filename="../mainwindow.cpp" line="1845"/>
        <source>Backup</source>
        <translation>Respaldo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="190"/>
        <location filename="../mainwindow.cpp" line="1833"/>
        <source>Restore</source>
        <translation>Restaurar</translation>
    </message>
    <message>
        <source>Schemas</source>
        <translation type="obsolete">Esquemas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="192"/>
        <location filename="../mainwindow.cpp" line="273"/>
        <location filename="../mainwindow.cpp" line="1560"/>
        <location filename="../mainwindow.cpp" line="1937"/>
        <source>Catalogs</source>
        <translation>Catálogos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="194"/>
        <location filename="../mainwindow.cpp" line="1566"/>
        <location filename="../mainwindow.cpp" line="2016"/>
        <source>Table Maintenance</source>
        <translation>Mantenimiento de Tablas</translation>
    </message>
    <message>
        <source>Metadata</source>
        <translation type="obsolete">Metadata</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="196"/>
        <location filename="../mainwindow.cpp" line="1885"/>
        <source>Process List</source>
        <translation>Lista de Procesos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="286"/>
        <source>In God we trust</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="287"/>
        <source>In a world without walls and fences, who needs windows and gates?</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="288"/>
        <source>Wellcome!!! Have a nice day.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="289"/>
        <source>MariaDB is great!!!</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="290"/>
        <source>Qt is great!!!</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="291"/>
        <source>Open space has more fresh air than closed Windows</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="292"/>
        <source>Microsoft gives you &quot;Windows&quot;, Linux a &quot;home&quot;!</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="206"/>
        <location filename="../mainwindow.cpp" line="1563"/>
        <source>Query</source>
        <translation>Consulta</translation>
    </message>
    <message>
        <source>PHP Script</source>
        <translation type="vanished">Script PHP</translation>
    </message>
    <message>
        <source>About CalÃ­ope</source>
        <translation type="vanished">Acerca de Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1557"/>
        <source>Restore Backup</source>
        <translation>Restaurar Respaldo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1569"/>
        <source>SQL Script</source>
        <translation>Script SQL</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="204"/>
        <source>SQL Query</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1692"/>
        <source>Refresh</source>
        <translation>Refrescar</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1695"/>
        <source>Read only</source>
        <translation>Solo lectura</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1698"/>
        <source>Create Database</source>
        <translation>Crear Base de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1701"/>
        <source>Delete Database</source>
        <translation>Borrar Base de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1689"/>
        <location filename="../mainwindow.cpp" line="1707"/>
        <source>Select recent file...</source>
        <translation>Seleccionar un archivo reciente...</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="208"/>
        <location filename="../mainwindow.cpp" line="870"/>
        <source>Database Comparision</source>
        <translation>Comparación de Bases de Datos</translation>
    </message>
    <message>
        <source>PostgreSQL On-Line Help</source>
        <translation type="vanished">Ayuda en Línea de PostgreSQL</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1662"/>
        <location filename="../mainwindow.cpp" line="1879"/>
        <source>MariaDB On-Line Help</source>
        <translation>Ayuda en Línea de MariaDB</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="832"/>
        <source>External Web Page</source>
        <translation>Página Web Externa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="840"/>
        <source>Visited sites</source>
        <translation>Sitios visitados</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="858"/>
        <source>The slave has been reset.</source>
        <translation>El esclavo ha sido reestablecido.</translation>
    </message>
    <message>
        <source>Database Comaparision</source>
        <translation type="obsolete">Comparación de Bases de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="943"/>
        <location filename="../mainwindow.cpp" line="1366"/>
        <source>Migrating data</source>
        <translation>Migrando datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="943"/>
        <location filename="../mainwindow.cpp" line="1366"/>
        <source>Abort</source>
        <translation>Abortar</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="956"/>
        <location filename="../mainwindow.cpp" line="1381"/>
        <location filename="../mainwindow.cpp" line="1493"/>
        <location filename="../mainwindow.cpp" line="1500"/>
        <location filename="../mainwindow.cpp" line="1510"/>
        <source>Database migration</source>
        <translation>Migración de bases de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="956"/>
        <location filename="../mainwindow.cpp" line="1381"/>
        <source>Database migration is only aviable for MariaDB and MySQL.</source>
        <translation>La migración de bases de datos solo está dispobible para MariaDB y MySQL.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="963"/>
        <source>Table count: %1</source>
        <translation>Conteo de tablas: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="198"/>
        <location filename="../mainwindow.cpp" line="1046"/>
        <source>Query Log</source>
        <translation>Log de Sentencias</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1072"/>
        <location filename="../mainwindow.cpp" line="1682"/>
        <source>Database information</source>
        <translation>Información de la base de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1083"/>
        <source>Save to Image</source>
        <translation>Guardar en Imagen</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1083"/>
        <source>Image files (%1)</source>
        <translation>Archivos de imagen (%1)</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1089"/>
        <location filename="../mainwindow.cpp" line="1283"/>
        <location filename="../mainwindow.cpp" line="1291"/>
        <location filename="../mainwindow.cpp" line="1402"/>
        <source>File saved at: %1</source>
        <translation>Archivo guardado en: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1163"/>
        <location filename="../mainwindow.cpp" line="1728"/>
        <source>HDD Usage Graphics</source>
        <translation>Gráfico de uso de HDD</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1172"/>
        <location filename="../mainwindow.cpp" line="1731"/>
        <source>Executed Queries</source>
        <translation>Consultas Ejecutadas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1181"/>
        <location filename="../mainwindow.cpp" line="1734"/>
        <source>Data Sent/Received</source>
        <translation>Datos Enviados/Recibidos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1190"/>
        <location filename="../mainwindow.cpp" line="1202"/>
        <source>Custom reports</source>
        <translation>Reportes personalizados</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1233"/>
        <location filename="../mainwindow.cpp" line="1740"/>
        <source>Slow Queries</source>
        <translation>Consultas lentas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1248"/>
        <source>All the replication slaves have been started.</source>
        <translation>Todos los esclavos de replicación han sido iniciados.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1254"/>
        <source>All the replication slaves hava been stoped.</source>
        <translation>Todos los esclavos de replicación han sido detenidos.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1281"/>
        <location filename="../mainwindow.cpp" line="1289"/>
        <source>Save file</source>
        <translation>Guardar archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1281"/>
        <location filename="../mainwindow.cpp" line="1289"/>
        <source>Settings files (*)</source>
        <translation>Archivos de configuración (*)</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1297"/>
        <source>All editors saved</source>
        <translation>Todos los editores guardados</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1493"/>
        <source>Migration done.</source>
        <translation>Migración realizada.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1530"/>
        <source>The database server has been shutdown.</source>
        <translation>El servidor de base de datos ha sido apagado.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1540"/>
        <source>Shows the About dialog for Qt.</source>
        <translation>Muestra el cuadro de diálogo de Acerda de Qt.</translation>
    </message>
    <message>
        <source>Shows the About dialog for CalÃ­ope.</source>
        <translation type="vanished">Muestra el cuadro de diálogo de Acerda de Calíope.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1545"/>
        <source>Connect to Server...</source>
        <translation>Conectarse al Servidor...</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1546"/>
        <source>Connect to a Database Server.</source>
        <translation>Conectarse a un Servidor de Base de Datos.</translation>
    </message>
    <message>
        <source>CalÃ­ope</source>
        <translation type="vanished">Calíope</translation>
    </message>
    <message>
        <source>MySQL Help</source>
        <translation type="vanished">Ayuda de MySQL</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1578"/>
        <source>View query log</source>
        <translation>Ver el log de consultas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1581"/>
        <location filename="../mainwindow.cpp" line="1873"/>
        <location filename="../mainwindow.cpp" line="1897"/>
        <source>MySQL On-Line Help</source>
        <translation>Ayuda en Línea de MySQL</translation>
    </message>
    <message>
        <source>PHP On-Line Help</source>
        <translation type="vanished">Ayuda en Línea de PHP</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1584"/>
        <location filename="../mainwindow.cpp" line="1810"/>
        <source>Preferences</source>
        <translation>Preferencias</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1587"/>
        <source>Processes</source>
        <translation>Procesos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1589"/>
        <source>&amp;File Toolbar</source>
        <translation>Barra de Herramientas de &amp;Archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1595"/>
        <source>&amp;Close connection</source>
        <translation>&amp;Cerrar conexión</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1596"/>
        <source>Close current database connection</source>
        <translation>Cerrar conexión de base de datos actual</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1598"/>
        <source>Cascade windows</source>
        <translation>Ventanas en cascada</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1601"/>
        <source>Next window</source>
        <translation>Próxima ventana</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1604"/>
        <source>Previous window</source>
        <translation>Ventana previa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1607"/>
        <source>Close current window</source>
        <translation>Cerrar ventana actual</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1610"/>
        <source>Close all windows</source>
        <translation>Cerrar todas las ventanas</translation>
    </message>
    <message>
        <source>Sort by title</source>
        <translation type="obsolete">Ordenar por título</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1616"/>
        <source>Shutdown Database Server</source>
        <translation>Apagar el Servidor de Base de Datos</translation>
    </message>
    <message>
        <source>CSS Editor</source>
        <translation type="vanished">Editor CSS</translation>
    </message>
    <message>
        <source>HTML Editor</source>
        <translation type="vanished">Editor HTML</translation>
    </message>
    <message>
        <source>JavaScript Editor</source>
        <translation type="vanished">Editor JavaScript</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1619"/>
        <source>Web site</source>
        <translation>Sitio web</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1622"/>
        <source>Full screen</source>
        <translation>Pantalla completa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1625"/>
        <source>Objects diagram</source>
        <translation>Diagrama de Objetos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1628"/>
        <source>Open file</source>
        <translation>Abrir archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1632"/>
        <source>Text Editor</source>
        <translation>Editor de Texto</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1635"/>
        <source>Stop Slave</source>
        <translation>Detener Esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1641"/>
        <source>Start Slave</source>
        <translation>Iniciar Esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1644"/>
        <source>Restart Slave</source>
        <translation>Reiniciar Esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1647"/>
        <source>Replication Information</source>
        <translation>Información de la Replicación</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1719"/>
        <source>Take a snapshot</source>
        <translation>Tomar una instantánea</translation>
    </message>
    <message>
        <source>CalÃ­ope source documentation</source>
        <translation type="vanished">Documentación fuente de Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2387"/>
        <source>Cannot load the translation.</source>
        <translation>No es posible cargar la traducción.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="791"/>
        <location filename="../mainwindow.cpp" line="1656"/>
        <source>Time Difference</source>
        <translation>Diferencia de Tiempo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1659"/>
        <source>Show the Slow Log</source>
        <translation>Mostrar el Slow Log</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="664"/>
        <source>Objects Diagram</source>
        <translation>Diagrama de Objetos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="202"/>
        <location filename="../mainwindow.cpp" line="1477"/>
        <location filename="../mainwindow.cpp" line="1767"/>
        <source>Object Migration</source>
        <translation>Migración de Objetos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="293"/>
        <source>I&apos;d rather be at $HOME</source>
        <translation>I&apos;d rather be at $HOME</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="334"/>
        <source>Error on saving application settings backup file.</source>
        <translation>Error al guardar el archivo de respaldo de las configuraciones de la aplicación.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="710"/>
        <source>Open a file</source>
        <translation>Abrir un archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="756"/>
        <source>The replication slave has been stoped.</source>
        <translation>El esclavo de replicación ha sido detenido.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="762"/>
        <source>The replication slave has been started.</source>
        <translation>El esclavo de replicación ha sido iniciado.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="768"/>
        <source>The replication slave has been rebooted.</source>
        <translation>El esclavo de replicación ha sido reiniciado.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="780"/>
        <source>Privileges flushed.</source>
        <translation>Privilegios refrescados.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="786"/>
        <source>Logs purged.</source>
        <translation>Logs purgados.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="792"/>
        <source>Seconds of difference: %1</source>
        <translation>Segundos de diferencia: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="800"/>
        <source>Select a date</source>
        <translation>Seleccione una fecha</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="864"/>
        <source>Logs flushed.</source>
        <translation>Registros limpiados.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1120"/>
        <location filename="../mainwindow.cpp" line="1722"/>
        <source>Calíope source documentation</source>
        <translation>Documentación del código fuente de Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1326"/>
        <source>Select a table</source>
        <translation>Seleccione una tabla</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1326"/>
        <source>Table:</source>
        <translation>Tabla:</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1391"/>
        <source>Save to Pdf</source>
        <translation>Guardar en Pdf</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1391"/>
        <source>Pdf &amp; Ps files (*.pdf *.ps)</source>
        <translation>Archivos Pdf &amp; Ps (*.pdf *.ps)</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1419"/>
        <source>Stop %1</source>
        <translation>Detener %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1424"/>
        <source>Start %1</source>
        <translation>Iniciar %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1429"/>
        <source>Reset %1</source>
        <translation>Restablecer %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1434"/>
        <source>Restart %1</source>
        <translation>Reiniciar %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1440"/>
        <source>All connections</source>
        <translation>Todas las conexiones</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1536"/>
        <source>&amp;Quit</source>
        <translation>&amp;Salir</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1537"/>
        <source>Exits the application.</source>
        <translation>Sale de laplicación.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1539"/>
        <source>About &amp;Qt</source>
        <translation>Acerca de &amp;Qt</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1542"/>
        <location filename="../mainwindow.cpp" line="2410"/>
        <source>About Calíope</source>
        <translation>Aceca de Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1543"/>
        <source>Shows the About dialog for Calíope.</source>
        <translation>Muestra el diálogo Acerca de Calíope.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1572"/>
        <source>Calíope</source>
        <translation>Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1575"/>
        <source>MariaDB Help</source>
        <translation>Ayuda de MariaDB</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1613"/>
        <source>Tile windows</source>
        <translation>Ventanas en mosaico</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1638"/>
        <source>Reset Slave</source>
        <translation>Restablecer esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1672"/>
        <source>&amp;Connection</source>
        <translation>&amp;Conexión</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1681"/>
        <source>Recent connections</source>
        <translation>Conexiones recientes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1683"/>
        <source>Reports</source>
        <translation>Reportes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1704"/>
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
        <location filename="../mainwindow.cpp" line="1821"/>
        <source>Users</source>
        <translation>Usuarios</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1867"/>
        <source>External Web page</source>
        <translation>Página Web externa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="300"/>
        <source>Connected successfully to: %1</source>
        <translation>Conectado satisfactoriamente a: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2029"/>
        <source>Result</source>
        <translation>Resultado</translation>
    </message>
    <message>
        <source>Databases</source>
        <translation type="obsolete">Bases de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1666"/>
        <location filename="../mainwindow.cpp" line="1686"/>
        <source>Editors</source>
        <translation>Editores</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1687"/>
        <source>Project files</source>
        <translation>Archivos de proyecto</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1668"/>
        <source>Open external web page</source>
        <translation>Abrir una página web externa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1669"/>
        <location filename="../mainwindow.cpp" line="2223"/>
        <source>&amp;File</source>
        <translation>&amp;Archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1670"/>
        <source>Recent files</source>
        <translation>Archivos recientes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1671"/>
        <source>&amp;Projects</source>
        <translation>&amp;Proyectos</translation>
    </message>
    <message>
        <source>&amp;Conecction</source>
        <translation type="obsolete">&amp;Conexión</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1673"/>
        <source>Change character set</source>
        <translation>Cambiar conjunto de caracteres</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1674"/>
        <source>Change database</source>
        <translation>Cambiar base de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1675"/>
        <location filename="../mainwindow.cpp" line="2302"/>
        <source>Replication</source>
        <translation>Replicación</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1676"/>
        <source>Maintenance</source>
        <translation>Mantenimiento</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1677"/>
        <source>&amp;View</source>
        <translation>&amp;Ver</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1678"/>
        <source>&amp;Languaje</source>
        <translation>&amp;Idioma</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1679"/>
        <source>&amp;Window</source>
        <translation>&amp;Ventana</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1680"/>
        <source>&amp;Help</source>
        <translation>&amp;Ayuda</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1710"/>
        <source>Clear recent files</source>
        <translation>Limpiar archivos recientes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1713"/>
        <source>Database comparation</source>
        <translation>Comparación de Bases de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1716"/>
        <source>Migrate database</source>
        <translation>Migrar base de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1039"/>
        <location filename="../mainwindow.cpp" line="1996"/>
        <source>Cannot connect to the server</source>
        <translation>No es posible conectarse al servidor</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1725"/>
        <source>Server information</source>
        <translation>Información del Servidor</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1737"/>
        <source>Create a custom report</source>
        <translation>Crear un reporte personalizado</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1743"/>
        <source>Tell us your comments</source>
        <translation>Dígamos sus comentarios</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1746"/>
        <source>Stop all Slaves</source>
        <translation>Detener todos los Esclavos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1749"/>
        <source>Start all Slaves</source>
        <translation>Iniciar todos los Esclavos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1752"/>
        <source>Export settings file</source>
        <translation>Exportar archivo de configuración</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1755"/>
        <source>Import settings file</source>
        <translation>Importar archivo de configuración</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1758"/>
        <source>Save all</source>
        <translation>Guardar todo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1761"/>
        <source>Migrate table</source>
        <translation>Migrar tabla</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1764"/>
        <source>Database metadata</source>
        <translation>Metadatos de la base de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2299"/>
        <source>General</source>
        <translation>General</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2305"/>
        <source>Logs</source>
        <translation>Registros</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2437"/>
        <source>Windows</source>
        <translation>Ventanas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2449"/>
        <source>Windows options</source>
        <translation>Opciones de ventanas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2508"/>
        <source>Character set changed to: %1</source>
        <translation>Conjunto de caracteres cambiado a: %1</translation>
    </message>
</context>
<context>
    <name>MariaDBHelp</name>
    <message>
        <location filename="../mariadbhelp.cpp" line="81"/>
        <source>MariaDB Help</source>
        <translation>Ayuda de MariaDB</translation>
    </message>
    <message>
        <location filename="../mariadbhelp.cpp" line="84"/>
        <source>Topics</source>
        <translation>Tópicos</translation>
    </message>
    <message>
        <location filename="../mariadbhelp.cpp" line="85"/>
        <source>Enter a Keyword</source>
        <translation>Ingrese una palabra clave</translation>
    </message>
    <message>
        <location filename="../mariadbhelp.cpp" line="121"/>
        <source>Syntax:</source>
        <translation>Sintaxis:</translation>
    </message>
    <message>
        <location filename="../mariadbhelp.cpp" line="122"/>
        <source>Example:</source>
        <translation>Ejemplo:</translation>
    </message>
    <message>
        <location filename="../mariadbhelp.cpp" line="124"/>
        <source>URL:</source>
        <translation>URL:</translation>
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
        <source>MySQL Help</source>
        <translation type="vanished">Ayuda de MySQL</translation>
    </message>
    <message>
        <source>Topics</source>
        <translation type="vanished">Tópicos</translation>
    </message>
    <message>
        <source>Enter a Keyword</source>
        <translation type="vanished">Ingrese una palabra clave</translation>
    </message>
    <message>
        <source>Syntax:</source>
        <translation type="vanished">Sintaxis:</translation>
    </message>
    <message>
        <source>Example:</source>
        <translation type="vanished">Ejemplo:</translation>
    </message>
    <message>
        <source>URL:</source>
        <translation type="vanished">URL:</translation>
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
    <name>ObjectMigration</name>
    <message>
        <location filename="../objectmigration.cpp" line="67"/>
        <source>Object Migration</source>
        <translation>Migración de Objetos</translation>
    </message>
    <message>
        <location filename="../objectmigration.cpp" line="70"/>
        <source>Options</source>
        <translation>Opciones</translation>
    </message>
    <message>
        <location filename="../objectmigration.cpp" line="71"/>
        <source>Objects</source>
        <translation>Objetos</translation>
    </message>
    <message>
        <location filename="../objectmigration.cpp" line="73"/>
        <source>Replace on destination</source>
        <translation>Reemplazar en el destino</translation>
    </message>
    <message>
        <location filename="../objectmigration.cpp" line="74"/>
        <source>Migrate</source>
        <translation>Migrar</translation>
    </message>
    <message>
        <location filename="../objectmigration.cpp" line="75"/>
        <source>Export data</source>
        <translation>Exportar datos</translation>
    </message>
    <message>
        <location filename="../objectmigration.cpp" line="76"/>
        <source>Skip Foreign Key checks</source>
        <translation>Saltar la revisión de llaves foráneas</translation>
    </message>
    <message>
        <location filename="../objectmigration.cpp" line="253"/>
        <source>Cannot connect to the server</source>
        <translation>No es posible conectarse al servidor</translation>
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
        <location filename="../preferences.cpp" line="222"/>
        <source>Preferences</source>
        <translation>Preferencias</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="226"/>
        <source>Select a style:</source>
        <translation>Seleccione un estilo:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="227"/>
        <source>Remember opened windows</source>
        <translation>Recordar ventanas abiertas</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="228"/>
        <source>Open last file used in the modules</source>
        <translation>Abrir el último archivo usado en los módulos</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="229"/>
        <source>Save Queries before execution?</source>
        <translation>¿Guardar Consultas antes de la ejecución?</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="230"/>
        <source>Appilcation Style</source>
        <translation>Estilo de la Aplicación</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="106"/>
        <source>General</source>
        <translation>General</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="98"/>
        <source>Change default background image</source>
        <translation>Cambiar la imagen de fondo predeterminada</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="173"/>
        <source>Count</source>
        <translation>Contador</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="174"/>
        <source>Collation</source>
        <translation>Colación</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="175"/>
        <source>Use SSL</source>
        <translation>Usar SSL</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="176"/>
        <source>Client Key File</source>
        <translation>Archivo SSL Llave del cliente</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="177"/>
        <source>Client Cert File</source>
        <translation>Archivo SSL Cert del cliente</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="195"/>
        <source>Application Theme</source>
        <translation>Tema de la Aplicación</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="199"/>
        <source>Code Snippets</source>
        <translation>Fragmentos de código</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="231"/>
        <source>Spaces</source>
        <translation>Espacios</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="233"/>
        <source>Tab size:</source>
        <translation>Tamaño del tabulador:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="234"/>
        <source>Enable automatic indentation.</source>
        <translation>Habilitar indentación automática.</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="235"/>
        <source>Clean white spaces at the end of the line.</source>
        <translation>Limpiar espacios en blanco al final de la línea.</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="236"/>
        <source>Save a backup copy before save a file.</source>
        <translation>Guardar una copia de seguridad antes de guardar el archivo.</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="242"/>
        <source>Use automatic reconnection</source>
        <translation>Usar reconexión automática</translation>
    </message>
    <message>
        <source>PHP On-Line Help:</source>
        <translation type="vanished">Ayuda en Línea de PHP:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="244"/>
        <source>MySQL On-Line Help:</source>
        <translation>Ayuda en Línea de MySQL:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="246"/>
        <source>MariaDB On-Line Help:</source>
        <translation>Ayuda en Línea de MariaDB:</translation>
    </message>
    <message>
        <source>Show Tabs and Spaces.</source>
        <translation type="obsolete">Mostar Tabulaciones y Espacios.</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="133"/>
        <source>Text Editor</source>
        <translation>Editor de Texto</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="137"/>
        <source>License Template</source>
        <translation>Plantilla de Licencia</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="141"/>
        <source>Network Settings</source>
        <translation>Configuración de la red</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="167"/>
        <source>Name</source>
        <translation>Nombre</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="170"/>
        <source>Server</source>
        <translation>Servidor</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="171"/>
        <source>Port</source>
        <translation>Puerto</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="169"/>
        <source>User</source>
        <translation>Usuario</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="178"/>
        <source>Password</source>
        <translation>Contraseña</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="172"/>
        <source>Database</source>
        <translation>Base de Datos</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="168"/>
        <source>Type</source>
        <translation>Tipo</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="187"/>
        <source>Connections Settings</source>
        <translation>Configuración de las Conexiones</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="191"/>
        <source>File Associations</source>
        <translation>Asociaciones de Archivo</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="238"/>
        <source>Enable query log</source>
        <translation>Habilitar el log de sentencias</translation>
    </message>
    <message>
        <source>PHP CLI Command:</source>
        <translation type="vanished">Comando PHP CLI:</translation>
    </message>
</context>
<context>
    <name>ProcessList</name>
    <message>
        <location filename="../processlist.cpp" line="139"/>
        <source>Process List</source>
        <translation>Lista de Procesos</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="51"/>
        <location filename="../processlist.cpp" line="61"/>
        <source>Id</source>
        <translation>Id</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="52"/>
        <location filename="../processlist.cpp" line="62"/>
        <source>User</source>
        <translation>Usuario</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="53"/>
        <location filename="../processlist.cpp" line="63"/>
        <source>Host</source>
        <translation>Huésped</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="54"/>
        <location filename="../processlist.cpp" line="64"/>
        <source>Database</source>
        <translation>Base de Datos</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="55"/>
        <location filename="../processlist.cpp" line="65"/>
        <source>Command</source>
        <translation>Comando</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="56"/>
        <location filename="../processlist.cpp" line="66"/>
        <source>Time</source>
        <translation>Tiempo</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="57"/>
        <location filename="../processlist.cpp" line="67"/>
        <source>State</source>
        <translation>Estado</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="58"/>
        <location filename="../processlist.cpp" line="68"/>
        <source>Info</source>
        <translation>Info</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="69"/>
        <source>Milliseconds</source>
        <translation>Milisegundos</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="70"/>
        <source>Stage</source>
        <translation>Etapa</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="71"/>
        <source>Max Stage</source>
        <translation>Máxima Etapa</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="72"/>
        <source>Progress</source>
        <translation>Progreso</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="73"/>
        <source>Memory</source>
        <translation>Memoria</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="74"/>
        <source>Examined Rows</source>
        <translation>Filas Examinadas</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="75"/>
        <source>Query Id</source>
        <translation>Consulta Id</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="76"/>
        <source>Binary data information</source>
        <translation>Información de datos binarios</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="149"/>
        <location filename="../processlist.cpp" line="152"/>
        <source>seconds</source>
        <translation>segundos</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="151"/>
        <source>Refresh rate:</source>
        <translation>Taza de refrescado:</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="142"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="143"/>
        <source>Stop refreshing</source>
        <translation>Detener refrescado</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="144"/>
        <source>Kill thread</source>
        <translation>Matar hilo</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="145"/>
        <source>Kills the given thread.</source>
        <translation>Mata el proceso dado.</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="146"/>
        <source>Kill idle threads</source>
        <translation>Matar hilos inactivos</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="147"/>
        <source>Kills thread exeding the given seconds inactive.</source>
        <translation>Mata los hilos que exedan el tiempo dado en segundos de inactividad.</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="148"/>
        <source>Time to kill threads.</source>
        <translation>Tiempo para matar los hios.</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="150"/>
        <source>Refresh rate.</source>
        <translation>Taza de refrescado.</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="153"/>
        <source>Kill query</source>
        <translation>Matar consulta</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="154"/>
        <source>Kills the given query.</source>
        <translation>Mata la consulta dada.</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="191"/>
        <source>Kill query: %1</source>
        <translation>Matar consulta %1</translation>
    </message>
    <message>
        <source>Kills thread exeding 30 seconds inactive.</source>
        <translation type="obsolete">Mata los hilos que exceden 30 inactivos.</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="190"/>
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
        <location filename="../projectfindreplace.cpp" line="110"/>
        <source>Find &amp; Replace</source>
        <translation>Búsqueda &amp; Reemplazo</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="114"/>
        <source>Text to find:</source>
        <translation>Texto a buscar:</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="116"/>
        <source>Text to replace:</source>
        <translation>Texto a reemplazar:</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="117"/>
        <source>Find</source>
        <translation>Buscar</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="118"/>
        <source>Case sensitive</source>
        <translation>Sensible a mayúsculas y minúsculas</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="119"/>
        <source>Whole words</source>
        <translation>Palabra completa</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="120"/>
        <source>Regular expression</source>
        <translation>Expresión regular</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="121"/>
        <source>Results</source>
        <translation>Resultados</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="122"/>
        <source>Replace</source>
        <translation>Remplazar</translation>
    </message>
    <message>
        <location filename="../projectfindreplace.cpp" line="190"/>
        <source>Do you really want to apply the changes?</source>
        <translation>¿Realmente desea aplicar los cambios?</translation>
    </message>
</context>
<context>
    <name>Projects</name>
    <message>
        <location filename="../projects.cpp" line="315"/>
        <source>New Project...</source>
        <translation>Nuevo Proyecto...</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="317"/>
        <source>Open Project...</source>
        <translation>Abrir Proyecto...</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="319"/>
        <source>Recent files</source>
        <translation>Archivos recientes</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="321"/>
        <source>Clear recent files</source>
        <translation>Limpiar archivos recientes</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="323"/>
        <source>Close current project</source>
        <translation>Cerrar el proyecto actual</translation>
    </message>
    <message>
        <source>Find in current project</source>
        <translation type="obsolete">Encontrar en el proyecto actual</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="325"/>
        <source>Find in project</source>
        <translation>Encontrar en el proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="327"/>
        <source>Project files</source>
        <translation>Archivos de proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="328"/>
        <source>Subversion</source>
        <translation>Subversion</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="329"/>
        <source>Add new file to project</source>
        <translation>Agregar un archivo nuevo al proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="331"/>
        <source>Add existing file to project</source>
        <translation>Agregar un archivo existente al proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="119"/>
        <source>Clean</source>
        <translation>Limpiar</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="150"/>
        <source>No projet</source>
        <translation>Sin proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="333"/>
        <source>Version &amp;control</source>
        <translation>Control de &amp;versiones</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="342"/>
        <source>Open a project</source>
        <translation>Abrir proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="342"/>
        <source>Project files (*.pro)</source>
        <translation>Archivos de Proyecto (*.pro)</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="416"/>
        <source>New project...</source>
        <translation>Nuevo proyecto...</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="425"/>
        <source>&amp;Name:</source>
        <translation>&amp;Nombre:</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="426"/>
        <source>Destination:</source>
        <translation>Destino:</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="428"/>
        <source>Poject information</source>
        <translation>Información del proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="432"/>
        <source>Load files</source>
        <translation>Cargar archivos</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="444"/>
        <source>Poject files</source>
        <translation>Archivos de proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="452"/>
        <source>Create new Project</source>
        <translation>Crear un nuevo Proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="465"/>
        <location filename="../projects.cpp" line="556"/>
        <location filename="../projects.cpp" line="567"/>
        <source>Info saved.</source>
        <translation>Información guardada.</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="522"/>
        <source>Select files</source>
        <translation>Seleccionar archivos</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="554"/>
        <source>File name</source>
        <translation>Nombre del archivo</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="559"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="566"/>
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
        <location filename="../result.cpp" line="252"/>
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
        <location filename="../result.cpp" line="192"/>
        <source>Result for: %1.%2</source>
        <translation>Resultado para %1.%2</translation>
    </message>
    <message>
        <location filename="../result.cpp" line="195"/>
        <source>Database or table does not exist.</source>
        <translation>Base de datos o la tabla no existen.</translation>
    </message>
</context>
<context>
    <name>SQLQuery</name>
    <message>
        <location filename="../sqlquery.cpp" line="163"/>
        <source>Query %1</source>
        <translation>Consulta: %1</translation>
    </message>
    <message>
        <source>Query toolbar</source>
        <translation type="obsolete">Barra de herramientas de consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="166"/>
        <source>Run</source>
        <translation>Correr</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="167"/>
        <source>Runs a query</source>
        <translation>Correr como consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="168"/>
        <source>Export</source>
        <translation>Exportar</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="169"/>
        <source>Export query output</source>
        <translation>Exportar salida de la consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="170"/>
        <source>History</source>
        <translation>Historial</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="172"/>
        <source>Show New Lines</source>
        <translation>Mostrar Nuevas Líneas</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="174"/>
        <source>Start SQL Player</source>
        <translation>Iniciar el SQL Player</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="176"/>
        <source>Split query</source>
        <translation>Dividir consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="178"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="180"/>
        <source>Start/Pause execution</source>
        <translation>Iniciar/Pausar ejecución</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="192"/>
        <source>Concatenate query output</source>
        <translation>Concatenar la salida de la consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="194"/>
        <source>Export table data for INSERT</source>
        <translation>Exportar los datos de la tabla para INSERT</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="196"/>
        <source>Export result data for INSERT</source>
        <translation>Exportar datos resultantes para INSERT</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="198"/>
        <source>Explain SELECT</source>
        <translation>Explicar SELECT</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="200"/>
        <source>Explain INSERT</source>
        <translation>Explicar INSERT</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="202"/>
        <source>Safe statements</source>
        <translation>Consultas seguras</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="204"/>
        <source>Show statements with error</source>
        <translation>Mostrar sentencias con error</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="206"/>
        <source>Explain UPDATE</source>
        <translation>Explicar UPDATE</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="208"/>
        <source>Repeate execution</source>
        <translation>Repetir ejecución</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="210"/>
        <source>Word wrap on result</source>
        <translation>Ajuste de línea en el resultado</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="211"/>
        <source>Log statements</source>
        <translation>Loguear sentencias</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="213"/>
        <source>TRIM columns in table</source>
        <translation>Recortar las columnas en la tabla</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="215"/>
        <source>Check tables status</source>
        <translation>Revisar el estado de las tablas</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="217"/>
        <source>Explain SELECT with Alias</source>
        <translation>Explicar SELECT con Alias</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="220"/>
        <source>Output as table.</source>
        <translation>Salida como tabla.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="221"/>
        <source>Same output as -v but with no headers.</source>
        <translation>Misma salida que -v pero sin encabezados.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="222"/>
        <source>Same output as -vv but with no query.</source>
        <translation>Misma salida que -vv pero sin la consulta.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="225"/>
        <source>Output as HTML.</source>
        <translation>Salida enHTML. </translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="226"/>
        <source>Output as text.</source>
        <translation>Salida en texto.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="227"/>
        <source>Output as XML.</source>
        <translation>Salida en XML.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="228"/>
        <source>Output in PDF.</source>
        <translation>Salida en PDF.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="495"/>
        <source>Script exectution</source>
        <translation>Ejecución de script</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="496"/>
        <source>Do you really want to execute the hole script?</source>
        <translation>¿Realmente desea ejecutar el script completo?</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="752"/>
        <source>Incorrect use of the EXPORT RESULT FOR INSERT Option. Example: EXPORT RESULT SELECT * FROM `PartitionedTale` PARTITION (`Partition1`), it only works for the current database and on SELECT *.</source>
        <translation>Uso incorrecto de la Opción EXPORT RESULT FOR INSERT. Ejemplo EXPORT RESULT SELECT * FROM `PartitionedTale` PARTITION (`Partition1`), sólo trabaja en la base de datos actual y con SELECT *.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="957"/>
        <source>Commit transacction</source>
        <translation>Guardar transacción</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="957"/>
        <source>Do you really want to commint changes?</source>
        <translation>¿Realmente desea aplicar los cambios?</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="970"/>
        <source>Do you really want to rollback changes?</source>
        <translation>¿Realmente desea revertir los cambios?</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="970"/>
        <source>Rollback transacction</source>
        <translation>Revertir transacción</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="223"/>
        <source>Output TAB separated with the query.</source>
        <translation>Salida separada con TAB con la consulta.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="224"/>
        <source>Same output as -t but with the query.</source>
        <translation>Misma salida que -t pero con la consulta.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="229"/>
        <source>Outputs columns as rows.</source>
        <translation>Salida en columnas como filas.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="231"/>
        <source>Begin transaction</source>
        <translation>Iniciar transacción</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="233"/>
        <source>Rollback transaction</source>
        <translation>Revertir transacción</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="235"/>
        <source>Commit transaction</source>
        <translation>Guardar transacción</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="504"/>
        <source>Could not execute statement on safe mode.</source>
        <translation>No es posible ejecutar esta consulta en modo seguro.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="505"/>
        <source>Safe mode</source>
        <translation>Modo seguro</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="559"/>
        <source>Save to Pdf</source>
        <translation>Guardar en Pdf</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="559"/>
        <source>Pdf &amp; Ps files (*.pdf *.ps)</source>
        <translation>Archivos Pdf &amp; Ps (*.pdf *.ps)</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="565"/>
        <source>File saved at: %1</source>
        <translation>Archivo guardado en: %1</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="686"/>
        <location filename="../sqlquery.cpp" line="741"/>
        <source>Select a file</source>
        <translation>Seleccione un archivo</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="689"/>
        <location filename="../sqlquery.cpp" line="744"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="697"/>
        <source>Incorrect use of the EXPORT DATA FOR INSERT Option. Example: EXPORT DATA FOR INSERT `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Exportar los datos de la tabla para INSERT. Ejemplo: EXPORT DATA FOR INSERT `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="601"/>
        <source>Incorrect use of the EXPLAIN SELECT Option. Example: SELECT * FROM `columns_pri`, it only works for the current database, the asterisk must be selected.</source>
        <translation>Uso incorrecto de la Opción Explicar SELECT. Ejemplo: SELECT * FROM `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="780"/>
        <source>Incorrect use of the EXPLAIN INSERT Option. Example: INSERT INTO `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Explicar INSERT. Ejemplo: INSERT INTO `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="908"/>
        <source>Incorrect use of the TRIM columns Option. Example: TRIM COLUMNS IN `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Recortar las columnas. Ejemplo: TRIM COLUMNS IN `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <source>Bad use of the EXPORT DATA FOR INSERT option.</source>
        <translation type="obsolete">Mal uso de la opción: Exportar los datos de la tabla para INSERT.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="793"/>
        <source>seconds</source>
        <translation>segundos</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="797"/>
        <location filename="../sqlquery.cpp" line="802"/>
        <source>minutes</source>
        <translation>minutos</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="804"/>
        <source>Elapsed: %1 %2. Remaining: %3 %4.
Total of queries: %5, remaining: %6.
Queries per second: %7.</source>
        <translation>Transcurrido: %1 %2. Restante: %3 %4.\nTotal de sentencias: %5, restantes: %6.\nConsultas por segundo: %7.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="860"/>
        <source>Incorrect use of the EXPLAIN UPDATE Option. Example: UPDATE `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Explicar UPDATE. Ejemplo: UPDATE `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="869"/>
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
        <location filename="../sqlquery.cpp" line="182"/>
        <source>Stop execution</source>
        <translation>Detener ejecución</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="184"/>
        <source>Run previous query</source>
        <translation>Ejecutar consulta previa</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="186"/>
        <source>Run next query</source>
        <translation>Ejecutar próxima consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="188"/>
        <source>Run first query</source>
        <translation>Ejecutar la primera consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="190"/>
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
        <location filename="../serverInformation.cpp" line="95"/>
        <source>Start time</source>
        <translation>Tiempo de inicio</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="96"/>
        <source>User</source>
        <translation>Usuario</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="97"/>
        <source>Time</source>
        <translation>Tiempo</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="98"/>
        <source>SQL Text</source>
        <translation>Texto SQL</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="156"/>
        <location filename="../serverInformation.cpp" line="158"/>
        <location filename="../serverInformation.cpp" line="546"/>
        <source>All</source>
        <translation>Todas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="161"/>
        <source>List of available connections</source>
        <translation>Lista de conexiones disponibles</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="347"/>
        <source>Server Information</source>
        <translation>Información del Servidor</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="350"/>
        <source>User:</source>
        <translation>Usuario:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="352"/>
        <source>Host:</source>
        <translation>Huésped:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="354"/>
        <source>Socket:</source>
        <translation>Socket:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="356"/>
        <source>Port:</source>
        <translation>Puerto:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="358"/>
        <source>Version:</source>
        <translation>Versión:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="360"/>
        <source>Connection id:</source>
        <translation>Id de la conexión:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="362"/>
        <source>Server status:</source>
        <translation>Estado del servidor:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="363"/>
        <source>Connection</source>
        <translation>Conexión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="364"/>
        <source>Status</source>
        <translation>Estado</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="374"/>
        <source>Skip 1000</source>
        <translation>Saltar 1000</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="399"/>
        <source>Refresh rate.</source>
        <translation>Taza de refrescado.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="400"/>
        <source>Refresh rate:</source>
        <translation>Taza de refrescado:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="401"/>
        <source>seconds</source>
        <translation>segundos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="428"/>
        <source>Data sent.</source>
        <translation>Datos enviados.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="430"/>
        <location filename="../serverInformation.cpp" line="449"/>
        <source>Transfer rate: %1 per second.</source>
        <translation>Radio de transferencia: %1 por segundo.</translation>
    </message>
    <message>
        <source>Refresh</source>
        <translation type="obsolete">Refrescar</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="368"/>
        <location filename="../serverInformation.cpp" line="376"/>
        <source>Replication Status</source>
        <translation>Estado del Replicador</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="369"/>
        <location filename="../serverInformation.cpp" line="379"/>
        <location filename="../serverInformation.cpp" line="384"/>
        <location filename="../serverInformation.cpp" line="387"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="370"/>
        <source>Skip 0</source>
        <translation>Saltar 0</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="371"/>
        <source>Skip 1</source>
        <translation>Saltar 1</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="372"/>
        <source>Skip 10</source>
        <translation>Saltar 10</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="373"/>
        <source>Skip 100</source>
        <translation>Saltar 100</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="375"/>
        <location filename="../serverInformation.cpp" line="381"/>
        <location filename="../serverInformation.cpp" line="385"/>
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
        <location filename="../serverInformation.cpp" line="377"/>
        <location filename="../serverInformation.cpp" line="378"/>
        <source>Variables</source>
        <translation>Variables</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="380"/>
        <location filename="../serverInformation.cpp" line="382"/>
        <location filename="../serverInformation.cpp" line="383"/>
        <location filename="../serverInformation.cpp" line="386"/>
        <location filename="../serverInformation.cpp" line="709"/>
        <source>Server Graphics</source>
        <translation>Gráficos del Servidor</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="388"/>
        <location filename="../serverInformation.cpp" line="389"/>
        <source>HDD Usage</source>
        <translation>Uso del HDD</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="391"/>
        <source>Filter</source>
        <translation>Filtro</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="392"/>
        <source>Show global variables</source>
        <translation>Mostrar variables globales</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="393"/>
        <source>Show global status</source>
        <translation>Mostrar el estado global</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="394"/>
        <source>Show session status</source>
        <translation>Mostrar estado de la sessión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="395"/>
        <source>Show session variables</source>
        <translation>Mostrar variables de sessión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="396"/>
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
        <location filename="../serverInformation.cpp" line="365"/>
        <source>Show server status</source>
        <translation>Mostrar estado del servidor</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="366"/>
        <source>Show slow queries</source>
        <translation>Mostrar las consultas lentas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="397"/>
        <source>Three characters at least</source>
        <translation>Tres caracteres como mínimo</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="398"/>
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
        <source>Data sent in MB.</source>
        <translation type="vanished">Datos enviados en MB.</translation>
    </message>
    <message>
        <source>Transfer rate: %1 Kb per second.</source>
        <translation type="vanished">Radio de transferencia: %1 Kb por segundo.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="447"/>
        <source>Data received in MB.</source>
        <translation>Datos recibidos e MB.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="452"/>
        <source>Miscellaneous values.</source>
        <translation>Valores miceláneos.</translation>
    </message>
    <message>
        <source>Other</source>
        <translation type="obsolete">Otros</translation>
    </message>
    <message>
        <source>Enter the default connection name and press Enter.</source>
        <translation type="vanished">Ingrese el nombre de la conexión predeterminada y presione Enter.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="562"/>
        <source>Database sizes description.</source>
        <translation>Descripción de los tamaños de las bases de datos.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="566"/>
        <location filename="../serverInformation.cpp" line="576"/>
        <source>Database</source>
        <translation>Base de Datos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="567"/>
        <location filename="../serverInformation.cpp" line="577"/>
        <source>Total</source>
        <translation>Total</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="568"/>
        <location filename="../serverInformation.cpp" line="578"/>
        <source>Data</source>
        <translation>Datos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="569"/>
        <location filename="../serverInformation.cpp" line="579"/>
        <source>Indexes</source>
        <translation>Índices</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="570"/>
        <source>Tables</source>
        <translation>Tablas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="571"/>
        <location filename="../serverInformation.cpp" line="580"/>
        <source>Rows</source>
        <translation>Filas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="575"/>
        <source>Detailed size table description. Table size greater than %1 MB.</source>
        <translation>Descripción detallada del tamaño de las tablas. Tamaño de tablas mayores a %1 MB.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="576"/>
        <source>Table name</source>
        <translation>Nombre de la tabla</translation>
    </message>
    <message>
        <source>Pending.</source>
        <translation type="obsolete">Pendiente.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="589"/>
        <location filename="../serverInformation.cpp" line="611"/>
        <source>There was an error determinating the DBMS type.</source>
        <translation>Hubo un error al determinar el tipo de DBMS.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="600"/>
        <source>Main server data.</source>
        <translation>Servidor principal de datos.</translation>
    </message>
    <message>
        <source>Uptime in days</source>
        <translation type="obsolete">Tiempo encendido en días</translation>
    </message>
    <message>
        <source>Variable</source>
        <translation type="obsolete">Variable</translation>
    </message>
    <message>
        <source>Value</source>
        <translation type="obsolete">Valor</translation>
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
        <location filename="../serverInformation.cpp" line="605"/>
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
        <source>Uptime in hours</source>
        <translation type="obsolete">Tiempo encendido en horas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="691"/>
        <source>Global status</source>
        <translation>Estado global</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="693"/>
        <source>Session status</source>
        <translation>Estado de sesión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="695"/>
        <source>Global variables</source>
        <translation>Variables globales</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="697"/>
        <source>Session variables</source>
        <translation>Variables de sesión</translation>
    </message>
    <message>
        <source>Average</source>
        <translation type="obsolete">Promedio</translation>
    </message>
    <message>
        <source>Slow queries since server started.</source>
        <translation type="obsolete">Consultas lentas desde que el servidor inició.</translation>
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
        <location filename="../staticfunctions.cpp" line="168"/>
        <source>Returns the absolute value of &lt;b&gt;X&lt;/b&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="171"/>
        <source>Adds expr2 to expr1 and returns the result.&lt;br /&gt;expr1 is a time or datetime expression, and expr2 is a time expression.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="178"/>
        <source>Returns the average value of expr.&lt;br /&gt;The DISTINCT option can be used as of MySQL 5.0.3 to return the average of the distinct values of expr.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="180"/>
        <source>Returns a string representation of the binary value of N.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="186"/>
        <source>Takes an expression of any type and produces a result value of a specified type.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="187"/>
        <location filename="../staticfunctions.cpp" line="188"/>
        <source>Returns the smallest integer value not less than X</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="189"/>
        <source>Returns the length of the string str, measured in characters. A multi-byte character counts as a single character.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="196"/>
        <source>Returns the string that results from concatenating the arguments.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="202"/>
        <source>Returns a count of the number of non-NULL values of expr in the rows retrieved by a SELECT statement.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="204"/>
        <location filename="../staticfunctions.cpp" line="205"/>
        <source>Returns the current date as a value in &apos;YYYY-MM-DD&apos; or YYYYMMDD format, depending on whether the function is used in a string or numeric context.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="207"/>
        <location filename="../staticfunctions.cpp" line="288"/>
        <source>Returns the current date and time as a value in &apos;YYYY-MM-DD HH:MM:SS&apos; or YYYYMMDDHHMMSS.uuuuuu format, &lt;br /&gt;depending on whether the function is used in a string or numeric context.&lt;br /&gt;The value is expressed in the current time zone.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="208"/>
        <source>Returns the user name and host name combination for the MySQL account that the server used to authenticate the current client.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="211"/>
        <source>Returns a string containing the date in the specified format.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="213"/>
        <source>Returns expr1 - expr2 expressed as a value in days from one date to the other.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="218"/>
        <source>Returns the name of the weekday for date.&lt;br /&gt;The language used for the name is controlled by the value of the lc_time_names system variable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="237"/>
        <source>Returns the largest integer value not greater than x.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="238"/>
        <source>Formats the number X to a format like &apos;#,###,###.##&apos;, rounded to D decimal places, and returns the result as a string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="241"/>
        <source>Returns a representation of the unix_timestamp argument as a value in &apos;YYYY-MM-DD HH:MM:SS&apos; or YYYYMMDDHHMMSS.uuuuuu format,&lt;br /&gt;depending on whether the function is used in a string or numeric context.&lt;br /&gt;If format is given, the result is formatted according to the format string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="245"/>
        <source>This function returns a string result with the concatenated non-NULL values from a group. It returns NULL if there are no non-NULL values.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="250"/>
        <source>If expr1 is not NULL, IFNULL() returns expr1; otherwise it returns expr2.&lt;br /&gt;IFNULL() returns a numeric or string value, depending on the context in which it is used.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="251"/>
        <source>Given the dotted-quad representation of an IPv4 network address as a string, returns an integer that represents the numeric value of the address in network byte order (big endian).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="252"/>
        <source>Given a numeric IPv4 network address in network byte order, returns the dotted-quad representation of the address as a binary string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="253"/>
        <source>Returns the position of the first occurrence of substring substr in string str.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="257"/>
        <source>If expr is NULL, ISNULL() returns 1, otherwise it returns 0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="260"/>
        <source>Returns the string str with all characters changed to lowercase according to the current character set mapping.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="263"/>
        <source>Returns the length of the string str, measured in bytes. &lt;br /&gt;A multi-byte character counts as multiple bytes.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="267"/>
        <source>Returns the position of the first occurrence of substring substr in string str, starting at position pos.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="271"/>
        <source>Returns the string str with all characters changed to lowercase according to the current character set mapping. </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="272"/>
        <source>Returns the string str, left-padded with the string padstr to a length of len characters.&lt;br /&gt;If str is longer than len, the return value is shortened to len characters.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="278"/>
        <source>Returns the maximum value of expr.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="279"/>
        <source>Calculates an MD5 128-bit checksum for the string. The value is returned as a string of 32 hex digits, or NULL if the argument was NULL.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="280"/>
        <source>Returns the microseconds from the time or datetime expression expr as a number in the range from 0 to 999999.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="281"/>
        <location filename="../staticfunctions.cpp" line="330"/>
        <location filename="../staticfunctions.cpp" line="332"/>
        <source>The forms without a len argument return a substring from string str starting at position pos. &lt;br /&gt;The forms with a len argument return a substring len characters long from string str, starting at position pos.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="282"/>
        <source>Returns the minimum value of expr.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="285"/>
        <source>Returns the month for date, in the range 1 to 12 for January to December.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="289"/>
        <source>Returns NULL if expr1 = expr2 is true, otherwise returns expr1.&lt;br /&gt;This is the same as CASE WHEN expr1 = expr2 THEN NULL ELSE expr1 END.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="304"/>
        <source>Returns a random floating-point value v in the range 0 &lt;= v &lt; 1.0. If a constant integer argument N is specified, it is used as the seed value, which produces a repeatable sequence of column values.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="309"/>
        <source>Returns the number of rows changed, deleted, or inserted by the last statement.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="310"/>
        <source>Returns the string str, right-padded with the string padstr to a length of len characters.&lt;br /&gt;If str is longer than len, the return value is shortened to len characters.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="312"/>
        <source>Returns the seconds argument, converted to hours, minutes, and seconds, as a TIME value.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="331"/>
        <source>Returns the substring from string str before count occurrences of the delimiter delim. &lt;br /&gt;If count is positive, everything to the left of the final delimiter (counting from the left) is returned. &lt;br /&gt;If count is negative, everything to the right of the final delimiter (counting from the right) is returned.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="210"/>
        <location filename="../staticfunctions.cpp" line="212"/>
        <source>These functions perform date arithmetic.&lt;br /&gt;The date argument specifies the starting date or datetime value.&lt;br /&gt;expr is an expression specifying the interval value to be added or subtracted from the starting date.&lt;br /&gt;expr is a string; it may start with a “-” for negative intervals.&lt;br /&gt;unit is a keyword indicating the units in which the expression should be interpreted.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="172"/>
        <source>This function decrypts data using the official AES (Advanced Encryption Standard) algorithm.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="173"/>
        <source>This function encrypts data using the official AES (Advanced Encryption Standard) algorithm.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="195"/>
        <source>Concatenate the strings with the given separator.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="197"/>
        <source>Returns the connection ID (thread ID) for the connection.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="246"/>
        <source>For a string argument str, HEX() returns a hexadecimal string representation of str where each byte of each character in str is converted to two hexadecimal digits.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="259"/>
        <source>Returns a value representing the first automatically generated value successfully inserted for an AUTO_INCREMENT column as a result of the most recently executed INSERT statement.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="276"/>
        <source>Returns a time value calculated from the hour, minute, and second arguments. </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="308"/>
        <source>Rounds the argument X to D decimal places.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="318"/>
        <source>Sleeps (pauses) for the number of seconds given by the duration argument, then returns 0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="333"/>
        <source>Returns expr1 – expr2 expressed as a value in the same format as expr1.&lt;br /&gt;expr1 is a time or datetime expression, and expr2 is a time expression.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="337"/>
        <source>Returns a string containing the time in the specified format.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="338"/>
        <source>Returns the time argument, converted to seconds.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="339"/>
        <source>Returns expr1 - expr2 expressed as a time value.&lt;br /&gt;expr1 and expr2 are time or date-and-time expressions, but both must be of the same type.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="341"/>
        <source>Returns datetime_expr2 - datetime_expr1, where datetime_expr1 and datetime_expr2 are date or datetime expressions.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="342"/>
        <source>Returns a day number (the number of days since year 0).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="343"/>
        <source>Returns the string str with all remstr prefixes or suffixes removed.&lt;br /&gt;If none of the specifiers BOTH, LEADING, or TRAILING is given, BOTH is assumed. remstr is optional and, if not specified, spaces are removed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="344"/>
        <source>Returns the number X, truncated to D decimal places.&lt;br /&gt;If D is 0, the result has no decimal point or fractional part.&lt;br /&gt;D can be negative to cause D digits left of the decimal point of the value X to become zero.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="345"/>
        <source>Returns the string str with all characters changed to uppercase according to the current character set mapping.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="349"/>
        <source>If called with no argument, returns a Unix timestamp (seconds since &apos;1970-01-01 00:00:00&apos; UTC) as an unsigned integer.&lt;br /&gt;If UNIX_TIMESTAMP() is called with a date argument, it returns the value of the argument as seconds since &apos;1970-01-01 00:00:00&apos; UTC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="352"/>
        <source>Returns the current MySQL user name and host name.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="356"/>
        <source>Returns a Universal Unique Identifier (UUID) generated according to RFC 4122</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="360"/>
        <source>Returns a string that indicates the MySQL server version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="361"/>
        <source>This function returns the week number for date.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="368"/>
        <source>If expr is greater than or equal to min and expr is less than or equal to max, BETWEEN returns 1, otherwise it returns 0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1497"/>
        <source>Uptime in days</source>
        <translation>Tiempo encendido en días</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1497"/>
        <source>Variable</source>
        <translation>Variable</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1497"/>
        <source>Value</source>
        <translation>Valor</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1499"/>
        <source>Number of aborted client connections.</source>
        <translation>Número de conexiones de cliente abortados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1504"/>
        <source>Number of aborted client connections per day.</source>
        <translation>Número de conexiones de cliente abortados por día.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1506"/>
        <source>Number of failed server connection attempts.</source>
        <translation>Número de intentos de conexión fallidos servidor.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1508"/>
        <source>Aborted connections per day</source>
        <translation>Conexiones abortadas por día</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1511"/>
        <source>Number of failed server connection attempts per day.</source>
        <translation>Número de conexiones abortadas por día.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1513"/>
        <source>Number of ROLLBACK commands executed.</source>
        <translation>Número de comandos ROLLBACK ejecutados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1518"/>
        <source>Number of ROLLBACK commands executed every second.</source>
        <translation>Número de comandos ROLLBACK ejecutados cada segundo.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1520"/>
        <source>Number of statements executed by the server.</source>
        <translation>Número de sentencias ejecutadas por el servidor.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1522"/>
        <source>Number of on-disk temporary tables created.</source>
        <translation>Número de tablas temporales creadas en disco.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1524"/>
        <source>Amount of free query cache memory.</source>
        <translation>La cantidad de memoria libre para la caché de consultas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1526"/>
        <source>Number of joins which did not use an index. If not zero, you may need to check table indexes.</source>
        <translation>Número de joins que no utilizaron un índice. Si no es cero, puede que tenga que comprobar los índices de tablas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1532"/>
        <source>Number of queries which took longer than long_query_time to run.</source>
        <translation>Número de consultas que tardaron más de LONG_QUERY_TIME para terminar.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1540"/>
        <source>The maximum number of simultaneous client connections.</source>
        <translation>El número máximo permitido de conexiones de cliente simultáneas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1542"/>
        <source>Max number of connections ever open at the same time.</source>
        <translation>Número máximo de conexiones abiertas al mismo tiempo.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1544"/>
        <source>DELETE commands executed</source>
        <translation>Comandos DELETE ejecutados</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1544"/>
        <source>Number of DELETE commands executed.</source>
        <translation>Número de comandos DELETE ejectados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1546"/>
        <source>INSERT commands executed</source>
        <translation>Comandos INSERT ejecutados</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1546"/>
        <source>Number of INSERT commands executed.</source>
        <translation>Número de comandos INSERT ejectados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1548"/>
        <source>UPDATE commands executed</source>
        <translation>Comandos UPDATE ejecutados</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1548"/>
        <source>Number of UPDATE commands executed.</source>
        <translation>Número de comandos UPDATE ejectados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1550"/>
        <source>SELECT commands executed</source>
        <translation>Comandos SELECT ejecutados</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1550"/>
        <source>Number of SELECT commands executed.</source>
        <translation>Número de comandos SELECT ejectados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1552"/>
        <source>Requests of the first index row</source>
        <translation>Solicitudes de la primera fila de índice</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1552"/>
        <source>Number of requests to read the first row from an index. A high value indicates many full index scans.</source>
        <translation>Número de peticiones para leer la primera fila de un índice. Un valor alto indica muchas exploraciones de índices completos.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1554"/>
        <source>Rate of SELECTs per full index scans</source>
        <translation>Tasa de SELECTs por exploraciones de índices completos</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1554"/>
        <source>Rate of SELECTs per full index scans. A value higher than 100 means you do more table scan than SELECTs.</source>
        <translation>Tasa de SELECTs por exploraciones de índices completos. Un valor superior a 100 significa hacer más exploración de tabla de SELECTs.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1556"/>
        <source>Read requests based on an index value</source>
        <translation>Solicitudes de lectura basadas en un valor de índice</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1556"/>
        <source>Number of row read requests based on an index value. A high value indicates indexes are regularly being used.</source>
        <translation>Solicitudes de lectura basadas en un valor de índice. Un valor alto indica que los índices se utilizan regularmente.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1558"/>
        <source>Wait timeout</source>
        <translation>Tiempo de espera</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1558"/>
        <source>Time in seconds that the server waits for a connection to become active before closing it.</source>
        <translation>Tiempo en segundos que el servidor espera que una conexión se active antes de cerrarla.</translation>
    </message>
    <message>
        <source>The number of days that the server has been up.</source>
        <translation type="obsolete">El número de días que el servidor ha estado en funcionamiento.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1497"/>
        <source>Description</source>
        <translation>Descripción</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1497"/>
        <source>Number of days the server has been running.</source>
        <translation>Número de días que el servidor ha estado funcionando.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1497"/>
        <source>Variable mame</source>
        <translation>Nombre de la variable</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1499"/>
        <source>Aborted clients</source>
        <translation>Clientes abortados</translation>
    </message>
    <message>
        <source>The number of connections that were aborted because the client died without closing the connection properly.</source>
        <translation type="obsolete">El número de conexiones que han sido abortadas debido a que el cliente murió sin cerrar la conexión correctamente.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1501"/>
        <source>Aborted clients per day</source>
        <translation>Clientes abortados por día</translation>
    </message>
    <message>
        <source>Rate of aborted clients per day.</source>
        <translation type="obsolete">Tasa de clientes abortados por día.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1506"/>
        <source>Aborted connections</source>
        <translation>Conexiones abortadas</translation>
    </message>
    <message>
        <source>The number of failed attempts to connect to the database server.</source>
        <translation type="obsolete">El número de intentos fallidos de conectarse al servidor de base de datos.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1513"/>
        <source>Executed rollbacks</source>
        <translation>Rollbacks ejecutados</translation>
    </message>
    <message>
        <source>The number of times each rollback statement has been executed.</source>
        <translation type="obsolete">El número de veces que cada sentencia de rollback se ha ejecutado.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1520"/>
        <source>Executed queries</source>
        <translation>Consultas ejecutadas</translation>
    </message>
    <message>
        <source>The number of statements executed by the server.</source>
        <translation type="obsolete">El número de sentencias ejecutadas por el servidor.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1515"/>
        <source>Rollbacks per second</source>
        <translation>Rollbacks por segundo</translation>
    </message>
    <message>
        <source>Rate of rollbacks per second.</source>
        <translation type="obsolete">Tasa de rollbacks por segundo.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1522"/>
        <source>Temporary disk tables created</source>
        <translation>Tablas temporales de disco creadas</translation>
    </message>
    <message>
        <source>The number of internal on-disk temporary tables created by the server while executing statements.</source>
        <translation type="obsolete">El número de tablas temporales en disco internas creadas por el servidor mientras ejecuta las sentencias.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1524"/>
        <source>Free cache memory</source>
        <translation>Memoria cache libre</translation>
    </message>
    <message>
        <source>The amount of free memory for the query cache.</source>
        <translation type="obsolete">La cantidad de memoria libre para la caché de consultas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1526"/>
        <source>Joins with full table scan</source>
        <translation>Joins con escaneo completo de tabla</translation>
    </message>
    <message>
        <source>The number of joins that perform table scans because they do not use indexes.</source>
        <translation type="obsolete">El número de joins que realizan escaneos de tablas porque que no utilizan índices.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1528"/>
        <source>Log slow queries</source>
        <translation>Guardar consultas lentas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1528"/>
        <source>Is the slow queries logging enabled?</source>
        <translation>¿Está el loggeo de consultas habilitado?</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1530"/>
        <source>Slow queries time in seconds</source>
        <translation>Tiempo de consultas lentas en segundos</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1530"/>
        <source>The number of seconds that determinate a slow query.</source>
        <translation>El número de segundos para determinar que una consulta es lenta.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1532"/>
        <source>Count of slow queries</source>
        <translation>Conteo de consultas lentas</translation>
    </message>
    <message>
        <source>The number of queries that have taken more than the allowed time.</source>
        <translation type="obsolete">El número de consultas que han tardado más que el tiempo permitido.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1534"/>
        <source>Idle connections</source>
        <translation>Conexiones inactivas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1534"/>
        <source>The number of connections that has been idle for more than 30 seconds.</source>
        <translation>El número de conexiones que ha estado inactivo durante más de 30 segundos.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1536"/>
        <source>Active connections</source>
        <translation>Conexiones activas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1536"/>
        <source>The number of connections that has been idle for less than 30 seconds.</source>
        <translation>El número de conexiones que ha estado inactivo durante menos de 30 segundos.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1538"/>
        <source>Total connections</source>
        <translation>Total de conexiones</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1538"/>
        <source>The number of active connections on the server.</source>
        <translation>El número de conexiones activas en el servidor.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1540"/>
        <source>Max connections aviable</source>
        <translation>Cantidad máxima de conexiones disponibles</translation>
    </message>
    <message>
        <source>The maximum permitted number of simultaneous client connections.</source>
        <translation type="obsolete">El número máximo permitido de conexiones de cliente simultáneas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1542"/>
        <source>Used connections</source>
        <translation>Conexiones usadas</translation>
    </message>
    <message>
        <source>The maximum number of connections that have been in use simultaneously since the server started.</source>
        <translation type="obsolete">El número máximo de conexiones que han sido utilizadas simultáneamente desde que el servidor se inició.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1573"/>
        <source>Date</source>
        <translation>Fecha</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1573"/>
        <source>Day</source>
        <translation>Día</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1573"/>
        <source>Total queries</source>
        <translation>Total de consultas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1574"/>
        <source>Average (in seconds)</source>
        <translation>Promedio (en segundos)</translation>
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
        <location filename="../tablemaintenance.cpp" line="122"/>
        <source>Table Maintenance</source>
        <translation>Mantenimiento de Tablas</translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="125"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="126"/>
        <source>Analyze</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="127"/>
        <source>Check</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="128"/>
        <source>Checksum</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="129"/>
        <source>Optimize</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="130"/>
        <source>Repair</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="131"/>
        <source>Databases</source>
        <translation>Bases de Datos</translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="133"/>
        <source>Clear selection</source>
        <translation>Limpiar selección</translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="134"/>
        <source>Select all</source>
        <translation>Seleccionar todo</translation>
    </message>
    <message>
        <location filename="../tablemaintenance.cpp" line="135"/>
        <source>Select local tables</source>
        <translation>Seleccionar tablas locales</translation>
    </message>
    <message>
        <source>Select base tables</source>
        <translation type="vanished">Seleccionar tablas base</translation>
    </message>
</context>
<context>
    <name>TextEditor</name>
    <message>
        <location filename="../texteditor.cpp" line="270"/>
        <source>Recent files</source>
        <translation>Archivos recientes</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="271"/>
        <location filename="../texteditor.cpp" line="282"/>
        <source>Symbols</source>
        <translation>Símbolos</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="509"/>
        <source>Print Script</source>
        <translation>Imprimir Script</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="535"/>
        <source>Clean</source>
        <translation>Limpiar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="837"/>
        <location filename="../texteditor.cpp" line="841"/>
        <source>Save file</source>
        <translation>Guardar archivo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="837"/>
        <source>Cannot save empty files.</source>
        <translation>No es posible guardar archivos en blanco.</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="303"/>
        <source>Cut line</source>
        <translation>Cortar línea</translation>
    </message>
    <message>
        <source>Explain SELECT</source>
        <translation type="obsolete">Explicar SELECT</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="322"/>
        <source>Show SQL Helpers in the completion</source>
        <translation>Mostar Ayudas de SQL en el completado</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="324"/>
        <source>Export to Pdf</source>
        <translation>Exportar a Pdf</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="325"/>
        <source>Export to Odt</source>
        <translation>Exportar a Odt</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="326"/>
        <source>Export to Html</source>
        <translation>Exportar a Html</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="327"/>
        <source>Export to Svg</source>
        <translation>Exportar a Svg</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="328"/>
        <source>Export to Image</source>
        <translation>Exportar a Imagen</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="329"/>
        <source>Toggle Comment</source>
        <translation>Intercambiar Comentarios</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="338"/>
        <source>Uppercase keywords</source>
        <translation>Hacer mayúsculas las palabras clave</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="339"/>
        <source>Lowercase keywords</source>
        <translation>Hacer minúsculas las palabras clave</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1124"/>
        <source>SQL Query: Save file...</source>
        <translation>Consulta SQL: Guardar archivo...</translation>
    </message>
    <message>
        <source>PHP Script: Save file...</source>
        <translation type="vanished">Script PHP: Guardar archivo...</translation>
    </message>
    <message>
        <source>CSS File: Save file...</source>
        <translation type="vanished">Archivo CSS: Guardar archivo...</translation>
    </message>
    <message>
        <source>HTML File: Save file...</source>
        <translation type="vanished">Archivo HTML: Guardar archivo...</translation>
    </message>
    <message>
        <source>JavaScript Script: Save file...</source>
        <translation type="vanished">Script JavaScript: Guardar archivo...</translation>
    </message>
    <message>
        <source>PHP files (*.php *.inc *.module)</source>
        <translation type="vanished">Archivos PHP (*.php *.inc *.module)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="851"/>
        <location filename="../texteditor.cpp" line="1654"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="274"/>
        <source>Edit Menu</source>
        <translation>Menú Editar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="275"/>
        <source>&amp;Export</source>
        <translation>&amp;Exportar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="272"/>
        <source>Sort by name</source>
        <translation>Ordenar por nombre</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="866"/>
        <location filename="../texteditor.cpp" line="1629"/>
        <location filename="../texteditor.cpp" line="1642"/>
        <location filename="../texteditor.cpp" line="1660"/>
        <location filename="../texteditor.cpp" line="1679"/>
        <location filename="../texteditor.cpp" line="1702"/>
        <source>File saved at: %1</source>
        <translation>Archivo guardado en: %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="283"/>
        <source>Clear</source>
        <translation>Limpiar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="284"/>
        <source>Open</source>
        <translation>Abrir</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="285"/>
        <source>Save</source>
        <translation>Guardar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="286"/>
        <source>Save as...</source>
        <translation>Guardar como...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="287"/>
        <source>Copy</source>
        <translation>Copiar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="288"/>
        <source>Cut</source>
        <translation>Cortar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="289"/>
        <source>Paste</source>
        <translation>Pegar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="290"/>
        <source>Undo</source>
        <translation>Deshacer</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="291"/>
        <source>Redo</source>
        <translation>Rehacer</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="292"/>
        <source>Word wrap</source>
        <translation>Ajuste de línea</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="293"/>
        <source>In</source>
        <translation>Acercar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="294"/>
        <source>Out</source>
        <translation>Aleajr</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="295"/>
        <source>Restore</source>
        <translation>Restaurar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="296"/>
        <source>Line...</source>
        <translation>Línea...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="297"/>
        <source>Select all</source>
        <translation>Seleccionar todo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="298"/>
        <source>Clear recent files</source>
        <translation>Limpiar archivos recientes</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="299"/>
        <source>Print...</source>
        <translation>Imprimir...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="300"/>
        <source>Reload file</source>
        <translation>Recargar archivo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="301"/>
        <source>Disable completion</source>
        <translation>Deshabilitar completado</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="302"/>
        <source>Show/Hide line numbers</source>
        <translation>Mostrar/Ocultar números de línea</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="304"/>
        <source>Version &amp;control</source>
        <translation>Control de &amp;versiones</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="308"/>
        <source>SQL Query %1</source>
        <translation>Consulta SQL %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="309"/>
        <source>Fill MariaDB Symbols</source>
        <translation>Llenar símbolos de MariaDB</translation>
    </message>
    <message>
        <source>Explain INSERT</source>
        <translation type="obsolete">Explicar INSERT</translation>
    </message>
    <message>
        <source>Run PHP Script</source>
        <translation type="vanished">Correr Script PHP</translation>
    </message>
    <message>
        <source>Check PHP Syntax</source>
        <translation type="vanished">Revisión de sintaxis PHP</translation>
    </message>
    <message>
        <source>PHP Script %1</source>
        <translation type="vanished">Script PHP %1</translation>
    </message>
    <message>
        <source>CSS Script %1</source>
        <translation type="vanished">Script CSS %1</translation>
    </message>
    <message>
        <source>HTML Script %1</source>
        <translation type="vanished">Script HTML %1</translation>
    </message>
    <message>
        <source>JavaScript Script %1</source>
        <translation type="vanished">Script JavaScript %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="312"/>
        <source>Text File %1</source>
        <translation>Archivo de Texto %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="330"/>
        <source>Highlight current line</source>
        <translation>Resaltar la línea actual</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="331"/>
        <source>Normal</source>
        <translation>Normal</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="332"/>
        <source>Vertical</source>
        <translation>Vertical</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="333"/>
        <source>Horizontal</source>
        <translation>Horizontal</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="334"/>
        <source>&amp;Show Symols</source>
        <translation>&amp;Mostrar Símbolos</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="335"/>
        <source>&amp;Normalize text</source>
        <translation>&amp;Normalizar texto</translation>
    </message>
    <message>
        <source>Insert licence template</source>
        <translation type="obsolete">Insertar plantilla de licencia</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1294"/>
        <source>SQL files (*.sql)</source>
        <translation>Archivos SQL (*.sql)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1335"/>
        <source>Zoom</source>
        <translation>Enfocar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1622"/>
        <source>Save to Pdf</source>
        <translation>Guardar en Pdf</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1622"/>
        <source>Pdf &amp; Ps files (*.pdf *.ps)</source>
        <translation>Archivos Pdf &amp; Ps (*.pdf *.ps)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1637"/>
        <source>Save to Odt</source>
        <translation>Guardar en Odt</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1637"/>
        <source>Odt files (*.odt)</source>
        <translation>Archivos Odt (*.odt)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1650"/>
        <source>Save to Html</source>
        <translation>Guardar en Html</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1650"/>
        <source>Html files (*.html *.htm)</source>
        <translation>Archivos Html (*.html *.htm)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1668"/>
        <source>Save to Svg</source>
        <translation>Guardar en Svg</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1668"/>
        <source>Svg files (*.svg)</source>
        <translation>Archivos Svg (*.svg)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1690"/>
        <source>Save to Image</source>
        <translation>Guardar en Imagen</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1690"/>
        <source>Image files (%1)</source>
        <translation>Archivos de imagen (%1)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="276"/>
        <source>&amp;File</source>
        <translation>&amp;Archivo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="277"/>
        <source>&amp;Edit</source>
        <translation>&amp;Editar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="278"/>
        <source>&amp;Options</source>
        <translation>&amp;Opciones</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="279"/>
        <source>&amp;Subversion</source>
        <translation>&amp;Subversion</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="280"/>
        <source>&amp;View</source>
        <translation>&amp;Ver</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="281"/>
        <source>View</source>
        <translation>Ver</translation>
    </message>
    <message>
        <source>Tool bar</source>
        <translation type="obsolete">Barra de herramientas</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1134"/>
        <source>The document has been modified.</source>
        <translation>El documento ha sido modificado.</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1135"/>
        <source>Do you want to save the changes?</source>
        <translation>¿Desea guardar los cambios?</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1199"/>
        <source>Go To Line...</source>
        <translation>Ir a la Línea...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1199"/>
        <source>Line number</source>
        <translation>Número de línea</translation>
    </message>
    <message>
        <source>CSS files (*.css)</source>
        <translation type="vanished">Archivos CSS (*.css)</translation>
    </message>
    <message>
        <source>HTML files (*.html *.htm)</source>
        <translation type="vanished">Archivos HTML (*.html *.htm)</translation>
    </message>
    <message>
        <source>JavaScript files (*.js)</source>
        <translation type="vanished">Archivos JavaScript (*.js)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1308"/>
        <source>Open a file</source>
        <translation>Abrir un archivo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1316"/>
        <source>Cannot read file %1:
%2.</source>
        <translation>No es posible leer el archivo %1: %2.</translation>
    </message>
</context>
<context>
    <name>Transaction</name>
    <message>
        <location filename="../dbms.cpp" line="2212"/>
        <source>Transaction started</source>
        <translation>Transacción iniciada</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="2227"/>
        <source>Transaction commited</source>
        <translation>Transacción guardada</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="2242"/>
        <source>Transaction rollbacked</source>
        <translation>Transacción revertida</translation>
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
