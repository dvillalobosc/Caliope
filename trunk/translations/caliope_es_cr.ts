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
        <location filename="../connectdialog.cpp" line="46"/>
        <source>Connect to a Database Server</source>
        <translation>Conectarse a un Servidor de Base de Datos</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="57"/>
        <source>Sort connection list by used times</source>
        <translation>Ordenar la lista de conexiones por las veces usadas</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="127"/>
        <source>Use a SSL connection</source>
        <translation>Usar conecxión SSL</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="131"/>
        <source>SSL Client Key file:</source>
        <translation>Archivo SSL Llave del cliente:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="132"/>
        <source>SSL Client Cert file:</source>
        <translation>Archivo SSL Cert del cliente:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="136"/>
        <source>&amp;Connection Name:</source>
        <translation>&amp;Nombre de la Conexión:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="138"/>
        <source>Connection &amp;Type:</source>
        <translation>&amp;Tipo de Conexión:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="139"/>
        <source>&amp;Server:</source>
        <translation>&amp;Servidor:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="140"/>
        <source>&amp;Port:</source>
        <translation>&amp;Puerto:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="141"/>
        <source>&amp;User:</source>
        <translation>&amp;Usuario:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="142"/>
        <source>Password:</source>
        <translation>Contraseña:</translation>
    </message>
    <message>
        <source>&amp;Password:</source>
        <translation type="obsolete">&amp;Contraseña:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="143"/>
        <source>Database:</source>
        <translation>Base de Datos:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="144"/>
        <source>Collation:</source>
        <translation>Cotejo:</translation>
    </message>
    <message>
        <location filename="../connectdialog.cpp" line="111"/>
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
        <location filename="../dbms.cpp" line="209"/>
        <location filename="../dbms.cpp" line="210"/>
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
        <location filename="../dbms.cpp" line="389"/>
        <location filename="../dbms.cpp" line="451"/>
        <source>Undefined Database driver.</source>
        <translation>Controlador de Base de datos indefinido.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="467"/>
        <source>Error:</source>
        <translation>Error:</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="475"/>
        <source>No error code provided.</source>
        <translation>No hay código de error proporcionado.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="576"/>
        <source>Select a file</source>
        <translation>Seleccione un archivo</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="585"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="589"/>
        <source>Data exported to %1</source>
        <translation>Datos exportados a %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="57"/>
        <source>Error</source>
        <translation>Error</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="54"/>
        <source>Count</source>
        <translation>Contador</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="54"/>
        <location filename="../dbms.cpp" line="1082"/>
        <source>Query</source>
        <translation>Consulta</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="54"/>
        <source>Error message</source>
        <translation>Mensaje de error</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="66"/>
        <source>Cannot open database</source>
        <translation>No es posible abrir la base de datos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="66"/>
        <source>Unable to establish a database connection.</source>
        <translation>Imposible establecer una conexión con la base de datos.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="133"/>
        <source>MySQL Version</source>
        <translation>Versión de MySQL</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="133"/>
        <source>Your version of MySQL seems to be less than 5.1.</source>
        <translation>Su versión de MySQL parece ser mejor a 5.1.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="156"/>
        <source>Stage: %1 of %2 &apos;%3&apos;. %4% of stage done.
Total progess: %5.</source>
        <translation>Etapa: %1 de %2 &apos;%3&apos;. %4% de la etapa realizado.\nProgreso total: %5.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="173"/>
        <source>%1 seconds</source>
        <translation>%1 segundos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="175"/>
        <source>%1 minutes</source>
        <translation>%1 minutos</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="177"/>
        <source>%1 hours</source>
        <translation>%1 horas</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="184"/>
        <source>Application closed</source>
        <translation>Aplicación cerrada</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="363"/>
        <location filename="../dbms.cpp" line="368"/>
        <source>Rows in set: %1. Elapsed time: %2.</source>
        <translation>Filas en el resultado: %1. Tiempo transcurrido: %2.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="378"/>
        <location filename="../dbms.cpp" line="384"/>
        <source>Rows in set: %1. Elapsed time: %2 seconds.</source>
        <translation>Filas en el resultado: %1. Tiempo transcurrido: %2.</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="791"/>
        <source>Could not execute statement. </source>
        <translation>No se puede ejecutar la sentencia. </translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1063"/>
        <source>Application started</source>
        <translation>Aplicación iniciada</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1078"/>
        <source>Line Number</source>
        <translation>Número de línea</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1079"/>
        <source>Session Id</source>
        <translation>Id de Sesión</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1080"/>
        <source>Date</source>
        <translation>Fecha</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1081"/>
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
        <location filename="../dbms.cpp" line="1352"/>
        <source>Could not change character set to: %1</source>
        <translation>No se puede cambiar el juego de caracteres a: %1</translation>
    </message>
</context>
<context>
    <name>DBarChartWidget</name>
    <message>
        <location filename="../serverInformation.cpp" line="710"/>
        <source>Total connections in the last 60 seconds</source>
        <translation>Total de conexiones en los últimos 60 segundos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="711"/>
        <source>Kb sent by second</source>
        <translation>Kb enviados por segundo</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="712"/>
        <source>Executed queries in the last 60 seconds</source>
        <translation>Consultas ejecutadas en los últimos 60 segundos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="764"/>
        <source>Current: %1</source>
        <translation>Actual %1</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="765"/>
        <source>Max: %1</source>
        <translation>Máximo: %1</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="766"/>
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
        <location filename="../dreportviewer.cpp" line="249"/>
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
        <location filename="../dreportviewer.cpp" line="241"/>
        <source>Save file</source>
        <translation>Guardar archivo</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="241"/>
        <source>Text files (%1)</source>
        <translation>Archivos de Texto (%1)</translation>
    </message>
    <message>
        <location filename="../dreportviewer.cpp" line="245"/>
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
        <location filename="../dwebview.cpp" line="58"/>
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
        <location filename="../dwebview.cpp" line="121"/>
        <location filename="../dwebview.cpp" line="146"/>
        <source>Loading page...</source>
        <translation>Cargando página...</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="127"/>
        <source>Page loaded.</source>
        <translation>Página cargada.</translation>
    </message>
    <message>
        <location filename="../dwebview.cpp" line="129"/>
        <source>Could not load page.</source>
        <translation>No se puede cargar la página.</translation>
    </message>
</context>
<context>
    <name>Database</name>
    <message>
        <location filename="../dbms.cpp" line="1483"/>
        <source>Database: %1</source>
        <translation>Base de Datos: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1484"/>
        <source>Total of tables: %1</source>
        <translation>Total de tablas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1485"/>
        <source>Total of views: %1</source>
        <translation>Total de vistas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1486"/>
        <source>Total of triggers: %1</source>
        <translation>Total de disparadores: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1487"/>
        <source>Total of rutines: %1</source>
        <translation>Total de rutinas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1488"/>
        <source>Total of events: %1</source>
        <translation>Total de eventos: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1489"/>
        <source>Tables size: %1</source>
        <translation>Tamaño total de las tablas: %1</translation>
    </message>
    <message>
        <location filename="../dbms.cpp" line="1490"/>
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
        <location filename="../databasecomparision.cpp" line="190"/>
        <location filename="../databasecomparision.cpp" line="199"/>
        <location filename="../databasecomparision.cpp" line="204"/>
        <location filename="../databasecomparision.cpp" line="215"/>
        <location filename="../databasecomparision.cpp" line="221"/>
        <source>Server</source>
        <translation>Servidor</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="190"/>
        <location filename="../databasecomparision.cpp" line="199"/>
        <location filename="../databasecomparision.cpp" line="204"/>
        <location filename="../databasecomparision.cpp" line="215"/>
        <location filename="../databasecomparision.cpp" line="221"/>
        <source>Database</source>
        <translation>Base de Datos</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="190"/>
        <location filename="../databasecomparision.cpp" line="199"/>
        <location filename="../databasecomparision.cpp" line="204"/>
        <location filename="../databasecomparision.cpp" line="215"/>
        <location filename="../databasecomparision.cpp" line="221"/>
        <source>Table</source>
        <translation>Tabla</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="190"/>
        <location filename="../databasecomparision.cpp" line="199"/>
        <location filename="../databasecomparision.cpp" line="204"/>
        <location filename="../databasecomparision.cpp" line="215"/>
        <location filename="../databasecomparision.cpp" line="221"/>
        <source>Data length</source>
        <translation>Tamaño de los datos</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="190"/>
        <location filename="../databasecomparision.cpp" line="199"/>
        <location filename="../databasecomparision.cpp" line="204"/>
        <location filename="../databasecomparision.cpp" line="215"/>
        <location filename="../databasecomparision.cpp" line="221"/>
        <source>Row count</source>
        <translation>Conteo de filas</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="190"/>
        <location filename="../databasecomparision.cpp" line="199"/>
        <location filename="../databasecomparision.cpp" line="204"/>
        <location filename="../databasecomparision.cpp" line="215"/>
        <location filename="../databasecomparision.cpp" line="221"/>
        <source>Checksum</source>
        <translation>Checksum</translation>
    </message>
    <message>
        <location filename="../databasecomparision.cpp" line="273"/>
        <source>Table does not exist.</source>
        <translation>La tabla no existe.</translation>
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
        <location filename="../fileselector.cpp" line="72"/>
        <source>SQL files (*.sql)</source>
        <translation>Archivos SQL (*.sql)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="75"/>
        <source>Text files (*.txt)</source>
        <translation>Archivos de Texto (*.txt)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="78"/>
        <source>Project files (*.pro)</source>
        <translation>Archivos de Proyecto (*.pro)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="81"/>
        <source>Bin files (*)</source>
        <translation>Archivos Bin (*)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="84"/>
        <source>Image files (*.png *.jpg *.bmp)</source>
        <translation>Archivo de imagen (*.png *.jpg *.bmp)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="87"/>
        <source>PEM files (*.pem)</source>
        <translation>Archivos PEM (*.pem)</translation>
    </message>
    <message>
        <location filename="../fileselector.cpp" line="117"/>
        <location filename="../fileselector.cpp" line="119"/>
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
        <location filename="../mainwindow.cpp" line="115"/>
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
        <location filename="../mainwindow.cpp" line="178"/>
        <location filename="../mainwindow.cpp" line="1248"/>
        <location filename="../mainwindow.cpp" line="1592"/>
        <location filename="../mainwindow.cpp" line="2004"/>
        <source>Server Information</source>
        <translation>Información del Servidor</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="180"/>
        <location filename="../mainwindow.cpp" line="1595"/>
        <source>User Administration</source>
        <translation>Administración de Usuarios</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="182"/>
        <location filename="../mainwindow.cpp" line="1598"/>
        <location filename="../mainwindow.cpp" line="1908"/>
        <source>Backup</source>
        <translation>Respaldo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="184"/>
        <location filename="../mainwindow.cpp" line="1896"/>
        <source>Restore</source>
        <translation>Restaurar</translation>
    </message>
    <message>
        <source>Schemas</source>
        <translation type="obsolete">Esquemas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="186"/>
        <location filename="../mainwindow.cpp" line="280"/>
        <location filename="../mainwindow.cpp" line="1604"/>
        <location filename="../mainwindow.cpp" line="2016"/>
        <source>Catalogs</source>
        <translation>Catálogos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="188"/>
        <location filename="../mainwindow.cpp" line="1610"/>
        <location filename="../mainwindow.cpp" line="2095"/>
        <source>Table Maintenance</source>
        <translation>Mantenimiento de Tablas</translation>
    </message>
    <message>
        <source>Metadata</source>
        <translation type="obsolete">Metadata</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="190"/>
        <location filename="../mainwindow.cpp" line="1965"/>
        <source>Process List</source>
        <translation>Lista de Procesos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="293"/>
        <source>In God we trust</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="294"/>
        <source>In a world without walls and fences, who needs windows and gates?</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="295"/>
        <source>Wellcome!!! Have a nice day.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="296"/>
        <source>MariaDB is great!!!</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="297"/>
        <source>Qt is great!!!</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="298"/>
        <source>Open space has more fresh air than closed Windows</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="299"/>
        <source>Microsoft gives you &quot;Windows&quot;, Linux a &quot;home&quot;!</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="198"/>
        <location filename="../mainwindow.cpp" line="1607"/>
        <source>Query</source>
        <translation>Consulta</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1616"/>
        <source>PHP Script</source>
        <translation>Script PHP</translation>
    </message>
    <message>
        <source>About CalÃ­ope</source>
        <translation type="vanished">Acerca de Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1601"/>
        <source>Restore Backup</source>
        <translation>Restaurar Respaldo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1613"/>
        <source>SQL Script</source>
        <translation>Script SQL</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="196"/>
        <source>SQL Query</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="200"/>
        <source>PHP</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1751"/>
        <source>Refresh</source>
        <translation>Refrescar</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1754"/>
        <source>Read only</source>
        <translation>Solo lectura</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1757"/>
        <source>Create Database</source>
        <translation>Crear Base de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1760"/>
        <source>Delete Database</source>
        <translation>Borrar Base de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1748"/>
        <location filename="../mainwindow.cpp" line="1766"/>
        <source>Select recent file...</source>
        <translation>Seleccionar un archivo reciente...</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="202"/>
        <location filename="../mainwindow.cpp" line="964"/>
        <source>Database Comparision</source>
        <translation>Comparación de Bases de Datos</translation>
    </message>
    <message>
        <source>PostgreSQL On-Line Help</source>
        <translation type="vanished">Ayuda en Línea de PostgreSQL</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1721"/>
        <location filename="../mainwindow.cpp" line="1959"/>
        <source>MariaDB On-Line Help</source>
        <translation>Ayuda en Línea de MariaDB</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="926"/>
        <source>External Web Page</source>
        <translation>Página Web Externa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="934"/>
        <source>Visited sites</source>
        <translation>Sitios visitados</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="952"/>
        <source>The slave has been reset.</source>
        <translation>El esclavo ha sido reestablecido.</translation>
    </message>
    <message>
        <source>Database Comaparision</source>
        <translation type="obsolete">Comparación de Bases de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1036"/>
        <location filename="../mainwindow.cpp" line="1480"/>
        <source>Migrating data</source>
        <translation>Migrando datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1036"/>
        <location filename="../mainwindow.cpp" line="1480"/>
        <source>Abort</source>
        <translation>Abortar</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1049"/>
        <location filename="../mainwindow.cpp" line="1494"/>
        <location filename="../mainwindow.cpp" line="1524"/>
        <location filename="../mainwindow.cpp" line="1531"/>
        <location filename="../mainwindow.cpp" line="1541"/>
        <source>Database migration</source>
        <translation>Migración de bases de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1049"/>
        <location filename="../mainwindow.cpp" line="1494"/>
        <source>Database migration is only aviable for MariaDB and MySQL.</source>
        <translation>La migración de bases de datos solo está dispobible para MariaDB y MySQL.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1056"/>
        <source>Table count: %1</source>
        <translation>Conteo de tablas: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="192"/>
        <location filename="../mainwindow.cpp" line="1139"/>
        <source>Query Log</source>
        <translation>Log de Sentencias</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1165"/>
        <location filename="../mainwindow.cpp" line="1741"/>
        <source>Database information</source>
        <translation>Información de la base de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1176"/>
        <source>Save to Image</source>
        <translation>Guardar en Imagen</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1176"/>
        <source>Image files (%1)</source>
        <translation>Archivos de imagen (%1)</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1182"/>
        <location filename="../mainwindow.cpp" line="1397"/>
        <location filename="../mainwindow.cpp" line="1405"/>
        <location filename="../mainwindow.cpp" line="1515"/>
        <source>File saved at: %1</source>
        <translation>Archivo guardado en: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1257"/>
        <location filename="../mainwindow.cpp" line="1787"/>
        <source>HDD Usage Graphics</source>
        <translation>Gráfico de uso de HDD</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1266"/>
        <location filename="../mainwindow.cpp" line="1790"/>
        <source>Executed Queries</source>
        <translation>Consultas Ejecutadas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1275"/>
        <location filename="../mainwindow.cpp" line="1793"/>
        <source>Data Sent/Received</source>
        <translation>Datos Enviados/Recibidos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1284"/>
        <location filename="../mainwindow.cpp" line="1296"/>
        <source>Custom reports</source>
        <translation>Reportes personalizados</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1327"/>
        <location filename="../mainwindow.cpp" line="1799"/>
        <source>Slow Queries</source>
        <translation>Consultas lentas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1342"/>
        <source>All the replication slaves have been started.</source>
        <translation>Todos los esclavos de replicación han sido iniciados.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1348"/>
        <source>All the replication slaves hava been stoped.</source>
        <translation>Todos los esclavos de replicación han sido detenidos.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1395"/>
        <location filename="../mainwindow.cpp" line="1403"/>
        <source>Save file</source>
        <translation>Guardar archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1395"/>
        <location filename="../mainwindow.cpp" line="1403"/>
        <source>Settings files (*)</source>
        <translation>Archivos de configuración (*)</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1411"/>
        <source>All editors saved</source>
        <translation>Todos los editores guardados</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1524"/>
        <source>Migration done.</source>
        <translation>Migración realizada.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1574"/>
        <source>The database server has been shutdown.</source>
        <translation>El servidor de base de datos ha sido apagado.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1584"/>
        <source>Shows the About dialog for Qt.</source>
        <translation>Muestra el cuadro de diálogo de Acerda de Qt.</translation>
    </message>
    <message>
        <source>Shows the About dialog for CalÃ­ope.</source>
        <translation type="vanished">Muestra el cuadro de diálogo de Acerda de Calíope.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1589"/>
        <source>Connect to Server...</source>
        <translation>Conectarse al Servidor...</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1590"/>
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
        <location filename="../mainwindow.cpp" line="1625"/>
        <source>View query log</source>
        <translation>Ver el log de consultas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1628"/>
        <location filename="../mainwindow.cpp" line="1953"/>
        <location filename="../mainwindow.cpp" line="1977"/>
        <source>MySQL On-Line Help</source>
        <translation>Ayuda en Línea de MySQL</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1631"/>
        <location filename="../mainwindow.cpp" line="1947"/>
        <source>PHP On-Line Help</source>
        <translation>Ayuda en Línea de PHP</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1634"/>
        <location filename="../mainwindow.cpp" line="1873"/>
        <source>Preferences</source>
        <translation>Preferencias</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1637"/>
        <source>Processes</source>
        <translation>Procesos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1639"/>
        <source>&amp;File Toolbar</source>
        <translation>Barra de Herramientas de &amp;Archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1645"/>
        <source>&amp;Close connection</source>
        <translation>&amp;Cerrar conexión</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1646"/>
        <source>Close current database connection</source>
        <translation>Cerrar conexión de base de datos actual</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1648"/>
        <source>Cascade windows</source>
        <translation>Ventanas en cascada</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1651"/>
        <source>Next window</source>
        <translation>Próxima ventana</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1654"/>
        <source>Previous window</source>
        <translation>Ventana previa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1657"/>
        <source>Close current window</source>
        <translation>Cerrar ventana actual</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1660"/>
        <source>Close all windows</source>
        <translation>Cerrar todas las ventanas</translation>
    </message>
    <message>
        <source>Sort by title</source>
        <translation type="obsolete">Ordenar por título</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1666"/>
        <source>Shutdown Database Server</source>
        <translation>Apagar el Servidor de Base de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1669"/>
        <source>CSS Editor</source>
        <translation>Editor CSS</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1672"/>
        <source>HTML Editor</source>
        <translation>Editor HTML</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1675"/>
        <source>JavaScript Editor</source>
        <translation>Editor JavaScript</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1678"/>
        <source>Web site</source>
        <translation>Sitio web</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1681"/>
        <source>Full screen</source>
        <translation>Pantalla completa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1684"/>
        <source>Objects diagram</source>
        <translation>Diagrama de Objetos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1687"/>
        <source>Open file</source>
        <translation>Abrir archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1691"/>
        <source>Text Editor</source>
        <translation>Editor de Texto</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1694"/>
        <source>Stop Slave</source>
        <translation>Detener Esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1700"/>
        <source>Start Slave</source>
        <translation>Iniciar Esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1703"/>
        <source>Restart Slave</source>
        <translation>Reiniciar Esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1706"/>
        <source>Replication Information</source>
        <translation>Información de la Replicación</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1778"/>
        <source>Take a snapshot</source>
        <translation>Tomar una instantánea</translation>
    </message>
    <message>
        <source>CalÃ­ope source documentation</source>
        <translation type="vanished">Documentación fuente de Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2479"/>
        <source>Cannot load the translation.</source>
        <translation>No es posible cargar la traducción.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="885"/>
        <location filename="../mainwindow.cpp" line="1715"/>
        <source>Time Difference</source>
        <translation>Diferencia de Tiempo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1718"/>
        <source>Show the Slow Log</source>
        <translation>Mostrar el Slow Log</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="687"/>
        <source>Objects Diagram</source>
        <translation>Diagrama de Objetos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="300"/>
        <source>I&apos;d rather be at $HOME</source>
        <translation>I&apos;d rather be at $HOME</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="754"/>
        <source>Open a file</source>
        <translation>Abrir un archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="850"/>
        <source>The replication slave has been stoped.</source>
        <translation>El esclavo de replicación ha sido detenido.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="856"/>
        <source>The replication slave has been started.</source>
        <translation>El esclavo de replicación ha sido iniciado.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="862"/>
        <source>The replication slave has been rebooted.</source>
        <translation>El esclavo de replicación ha sido reiniciado.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="874"/>
        <source>Privileges flushed.</source>
        <translation>Privilegios refrescados.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="880"/>
        <source>Logs purged.</source>
        <translation>Logs purgados.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="886"/>
        <source>Seconds of difference: %1</source>
        <translation>Segundos de diferencia: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="894"/>
        <source>Select a date</source>
        <translation>Seleccione una fecha</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="958"/>
        <source>Logs flushed.</source>
        <translation>Registros limpiados.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1214"/>
        <location filename="../mainwindow.cpp" line="1781"/>
        <source>Calíope source documentation</source>
        <translation>Documentación del código fuente de Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1440"/>
        <source>Select a table</source>
        <translation>Seleccione una tabla</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1440"/>
        <source>Table:</source>
        <translation>Tabla:</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1504"/>
        <source>Save to Pdf</source>
        <translation>Guardar en Pdf</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1504"/>
        <source>Pdf &amp; Ps files (*.pdf *.ps)</source>
        <translation>Archivos Pdf &amp; Ps (*.pdf *.ps)</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1580"/>
        <source>&amp;Quit</source>
        <translation>&amp;Salir</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1581"/>
        <source>Exits the application.</source>
        <translation>Sale de laplicación.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1583"/>
        <source>About &amp;Qt</source>
        <translation>Acerca de &amp;Qt</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1586"/>
        <location filename="../mainwindow.cpp" line="2502"/>
        <source>About Calíope</source>
        <translation>Aceca de Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1587"/>
        <source>Shows the About dialog for Calíope.</source>
        <translation>Muestra el diálogo Acerca de Calíope.</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1619"/>
        <source>Calíope</source>
        <translation>Calíope</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1622"/>
        <source>MariaDB Help</source>
        <translation>Ayuda de MariaDB</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1663"/>
        <source>Tile windows</source>
        <translation>Ventanas en mosaico</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1697"/>
        <source>Reset Slave</source>
        <translation>Restablecer esclavo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1731"/>
        <source>&amp;Connection</source>
        <translation>&amp;Conexión</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1740"/>
        <source>Recent connections</source>
        <translation>Conexiones recientes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1742"/>
        <source>Reports</source>
        <translation>Reportes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1763"/>
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
        <location filename="../mainwindow.cpp" line="1884"/>
        <source>Users</source>
        <translation>Usuarios</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1941"/>
        <source>External Web page</source>
        <translation>Página Web externa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="307"/>
        <source>Connected successfully to: %1</source>
        <translation>Conectado satisfactoriamente a: %1</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2107"/>
        <source>Result</source>
        <translation>Resultado</translation>
    </message>
    <message>
        <source>Databases</source>
        <translation type="obsolete">Bases de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1725"/>
        <location filename="../mainwindow.cpp" line="1745"/>
        <source>Editors</source>
        <translation>Editores</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1746"/>
        <source>Project files</source>
        <translation>Archivos de proyecto</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1727"/>
        <source>Open external web page</source>
        <translation>Abrir una página web externa</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1728"/>
        <location filename="../mainwindow.cpp" line="2306"/>
        <source>&amp;File</source>
        <translation>&amp;Archivo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1729"/>
        <source>Recent files</source>
        <translation>Archivos recientes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1730"/>
        <source>&amp;Projects</source>
        <translation>&amp;Proyectos</translation>
    </message>
    <message>
        <source>&amp;Conecction</source>
        <translation type="obsolete">&amp;Conexión</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1732"/>
        <source>Change character set</source>
        <translation>Cambiar conjunto de caracteres</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1733"/>
        <source>Change database</source>
        <translation>Cambiar base de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1734"/>
        <location filename="../mainwindow.cpp" line="2392"/>
        <source>Replication</source>
        <translation>Replicación</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1735"/>
        <source>Maintenance</source>
        <translation>Mantenimiento</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1736"/>
        <source>&amp;View</source>
        <translation>&amp;Ver</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1737"/>
        <source>&amp;Languaje</source>
        <translation>&amp;Idioma</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1738"/>
        <source>&amp;Window</source>
        <translation>&amp;Ventana</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1739"/>
        <source>&amp;Help</source>
        <translation>&amp;Ayuda</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1769"/>
        <source>Clear recent files</source>
        <translation>Limpiar archivos recientes</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1772"/>
        <source>Database comparation</source>
        <translation>Comparación de Bases de Datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1775"/>
        <source>Migrate database</source>
        <translation>Migrar base de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1132"/>
        <location filename="../mainwindow.cpp" line="2075"/>
        <source>Cannot connect to the server</source>
        <translation>No es posible conectarse al servidor</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1784"/>
        <source>Server information</source>
        <translation>Información del Servidor</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1796"/>
        <source>Create a custom report</source>
        <translation>Crear un reporte personalizado</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1802"/>
        <source>Tell us your comments</source>
        <translation>Dígamos sus comentarios</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1805"/>
        <source>Stop all Slaves</source>
        <translation>Detener todos los Esclavos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1808"/>
        <source>Start all Slaves</source>
        <translation>Iniciar todos los Esclavos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1811"/>
        <source>Export settings file</source>
        <translation>Exportar archivo de configuración</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1814"/>
        <source>Import settings file</source>
        <translation>Importar archivo de configuración</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1817"/>
        <source>Save all</source>
        <translation>Guardar todo</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1820"/>
        <source>Migrate table</source>
        <translation>Migrar tabla</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="1823"/>
        <source>Database metadata</source>
        <translation>Metadatos de la base de datos</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2389"/>
        <source>General</source>
        <translation>General</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2395"/>
        <source>Logs</source>
        <translation>Registros</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2529"/>
        <source>Windows</source>
        <translation>Ventanas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2540"/>
        <source>Windows options</source>
        <translation>Opciones de ventanas</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="2599"/>
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
        <location filename="../preferences.cpp" line="231"/>
        <source>Preferences</source>
        <translation>Preferencias</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="235"/>
        <source>Select a style:</source>
        <translation>Seleccione un estilo:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="236"/>
        <source>Remember opened windows</source>
        <translation>Recordar ventanas abiertas</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="237"/>
        <source>Open last file used in the modules</source>
        <translation>Abrir el último archivo usado en los módulos</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="238"/>
        <source>Save Queries before execution?</source>
        <translation>¿Guardar Consultas antes de la ejecución?</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="239"/>
        <source>Appilcation Style</source>
        <translation>Estilo de la Aplicación</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="109"/>
        <source>General</source>
        <translation>General</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="101"/>
        <source>Change default background image</source>
        <translation>Cambiar la imagen de fondo predeterminada</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="176"/>
        <source>Count</source>
        <translation>Contador</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="177"/>
        <source>Collation</source>
        <translation>Colación</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="178"/>
        <source>Use SSL</source>
        <translation>Usar SSL</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="179"/>
        <source>Client Key File</source>
        <translation>Archivo SSL Llave del cliente</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="180"/>
        <source>Client Cert File</source>
        <translation>Archivo SSL Cert del cliente</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="208"/>
        <source>Application Theme</source>
        <translation>Tema de la Aplicación</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="240"/>
        <source>Spaces</source>
        <translation>Espacios</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="242"/>
        <source>Tab size:</source>
        <translation>Tamaño del tabulador:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="243"/>
        <source>Enable automatic indentation.</source>
        <translation>Habilitar indentación automática.</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="244"/>
        <source>Clean white spaces at the end of the line.</source>
        <translation>Limpiar espacios en blanco al final de la línea.</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="245"/>
        <source>Save a backup copy before save a file.</source>
        <translation>Guardar una copia de seguridad antes de guardar el archivo.</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="252"/>
        <source>Use automatic reconnection</source>
        <translation>Usar reconexión automática</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="254"/>
        <source>PHP On-Line Help:</source>
        <translation>Ayuda en Línea de PHP:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="256"/>
        <source>MySQL On-Line Help:</source>
        <translation>Ayuda en Línea de MySQL:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="258"/>
        <source>MariaDB On-Line Help:</source>
        <translation>Ayuda en Línea de MariaDB:</translation>
    </message>
    <message>
        <source>Show Tabs and Spaces.</source>
        <translation type="obsolete">Mostar Tabulaciones y Espacios.</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="136"/>
        <source>Text Editor</source>
        <translation>Editor de Texto</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="140"/>
        <source>License Template</source>
        <translation>Plantilla de Licencia</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="144"/>
        <source>Network Settings</source>
        <translation>Configuración de la red</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="170"/>
        <source>Name</source>
        <translation>Nombre</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="173"/>
        <source>Server</source>
        <translation>Servidor</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="174"/>
        <source>Port</source>
        <translation>Puerto</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="172"/>
        <source>User</source>
        <translation>Usuario</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="181"/>
        <source>Password</source>
        <translation>Contraseña</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="175"/>
        <source>Database</source>
        <translation>Base de Datos</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="171"/>
        <source>Type</source>
        <translation>Tipo</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="190"/>
        <source>Connections Settings</source>
        <translation>Configuración de las Conexiones</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="194"/>
        <source>File Associations</source>
        <translation>Asociaciones de Archivo</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="247"/>
        <source>Enable query log</source>
        <translation>Habilitar el log de sentencias</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="251"/>
        <source>PHP CLI Command:</source>
        <translation>Comando PHP CLI:</translation>
    </message>
    <message>
        <location filename="../preferences.cpp" line="204"/>
        <source>PHP</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>ProcessList</name>
    <message>
        <location filename="../processlist.cpp" line="129"/>
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
        <location filename="../processlist.cpp" line="107"/>
        <source>seconds</source>
        <translation>segundos</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="132"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="133"/>
        <source>Stop refreshing</source>
        <translation>Detener refrescado</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="134"/>
        <source>Kill thread</source>
        <translation>Matar hilo</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="135"/>
        <source>Kills the given thread.</source>
        <translation>Mata el proceso dado.</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="136"/>
        <source>Kill idle threads</source>
        <translation>Matar hilos inactivos</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="137"/>
        <source>Kills thread exeding the given seconds inactive.</source>
        <translation>Mata los hilos que exedan el tiempo dado en segundos de inactividad.</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="138"/>
        <source>Time to kill threads.</source>
        <translation>Tiempo para matar los hios.</translation>
    </message>
    <message>
        <source>Kills thread exeding 30 seconds inactive.</source>
        <translation type="obsolete">Mata los hilos que exceden 30 inactivos.</translation>
    </message>
    <message>
        <location filename="../processlist.cpp" line="163"/>
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
        <location filename="../projects.cpp" line="341"/>
        <source>New Project...</source>
        <translation>Nuevo Proyecto...</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="343"/>
        <source>Open Project...</source>
        <translation>Abrir Proyecto...</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="345"/>
        <source>Recent files</source>
        <translation>Archivos recientes</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="347"/>
        <source>Clear recent files</source>
        <translation>Limpiar archivos recientes</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="349"/>
        <source>Close current project</source>
        <translation>Cerrar el proyecto actual</translation>
    </message>
    <message>
        <source>Find in current project</source>
        <translation type="obsolete">Encontrar en el proyecto actual</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="351"/>
        <source>Find in project</source>
        <translation>Encontrar en el proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="353"/>
        <source>Project files</source>
        <translation>Archivos de proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="354"/>
        <source>Subversion</source>
        <translation>Subversion</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="355"/>
        <source>Add new file to project</source>
        <translation>Agregar un archivo nuevo al proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="357"/>
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
        <location filename="../projects.cpp" line="359"/>
        <source>Version &amp;control</source>
        <translation>Control de &amp;versiones</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="368"/>
        <source>Open a project</source>
        <translation>Abrir proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="368"/>
        <source>Project files (*.pro)</source>
        <translation>Archivos de Proyecto (*.pro)</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="442"/>
        <source>New project...</source>
        <translation>Nuevo proyecto...</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="451"/>
        <source>&amp;Name:</source>
        <translation>&amp;Nombre:</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="452"/>
        <source>Destination:</source>
        <translation>Destino:</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="454"/>
        <source>Poject information</source>
        <translation>Información del proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="458"/>
        <source>Load files</source>
        <translation>Cargar archivos</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="470"/>
        <source>Poject files</source>
        <translation>Archivos de proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="478"/>
        <source>Create new Project</source>
        <translation>Crear un nuevo Proyecto</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="491"/>
        <location filename="../projects.cpp" line="582"/>
        <location filename="../projects.cpp" line="593"/>
        <source>Info saved.</source>
        <translation>Información guardada.</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="548"/>
        <source>Select files</source>
        <translation>Seleccionar archivos</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="580"/>
        <source>File name</source>
        <translation>Nombre del archivo</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="585"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../projects.cpp" line="592"/>
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
        <location filename="../sqlquery.cpp" line="157"/>
        <source>Query %1</source>
        <translation>Consulta: %1</translation>
    </message>
    <message>
        <source>Query toolbar</source>
        <translation type="obsolete">Barra de herramientas de consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="160"/>
        <source>Run</source>
        <translation>Correr</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="161"/>
        <source>Runs a query</source>
        <translation>Correr como consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="162"/>
        <source>Export</source>
        <translation>Exportar</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="163"/>
        <source>Export query output</source>
        <translation>Exportar salida de la consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="164"/>
        <source>History</source>
        <translation>Historial</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="166"/>
        <source>Show New Lines</source>
        <translation>Mostrar Nuevas Líneas</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="168"/>
        <source>Start SQL Player</source>
        <translation>Iniciar el SQL Player</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="170"/>
        <source>Split query</source>
        <translation>Dividir consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="172"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="174"/>
        <source>Start/Pause execution</source>
        <translation>Iniciar/Pausar ejecución</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="186"/>
        <source>Concatenate query output</source>
        <translation>Concatenar la salida de la consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="188"/>
        <source>Export table data for INSERT</source>
        <translation>Exportar los datos de la tabla para INSERT</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="190"/>
        <source>Explain SELECT</source>
        <translation>Explicar SELECT</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="192"/>
        <source>Explain INSERT</source>
        <translation>Explicar INSERT</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="194"/>
        <source>Safe statements</source>
        <translation>Consultas seguras</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="196"/>
        <source>Show statements with error</source>
        <translation>Mostrar sentencias con error</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="198"/>
        <source>Explain UPDATE</source>
        <translation>Explicar UPDATE</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="200"/>
        <source>Repeate execution</source>
        <translation>Repetir ejecución</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="202"/>
        <source>Word wrap on result</source>
        <translation>Ajuste de línea en el resultado</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="203"/>
        <source>Log statements</source>
        <translation>Loguear sentencias</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="205"/>
        <source>TRIM columns in table</source>
        <translation>Recortar las columnas en la tabla</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="207"/>
        <source>Check tables status</source>
        <translation>Revisar el estado de las tablas</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="209"/>
        <source>Explain SELECT with Alias</source>
        <translation>Explicar SELECT con Alias</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="212"/>
        <source>Output as table.</source>
        <translation>Salida como tabla.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="213"/>
        <source>Same output as -v but with no headers.</source>
        <translation>Misma salida que -v pero sin encabezados.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="214"/>
        <source>Same output as -vv but with no query.</source>
        <translation>Misma salida que -vv pero sin la consulta.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="217"/>
        <source>Output as HTML.</source>
        <translation>Salida enHTML. </translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="218"/>
        <source>Output as text.</source>
        <translation>Salida en texto.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="219"/>
        <source>Output as XML.</source>
        <translation>Salida en XML.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="220"/>
        <source>Output in PDF.</source>
        <translation>Salida en PDF.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="215"/>
        <source>Output TAB separated with the query.</source>
        <translation>Salida separada con TAB con la consulta.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="216"/>
        <source>Same output as -t but with the query.</source>
        <translation>Misma salida que -t pero con la consulta.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="221"/>
        <source>Outputs columns as rows.</source>
        <translation>Salida en columnas como filas.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="461"/>
        <source>Could not execute statement on safe mode.</source>
        <translation>No es posible ejecutar esta consulta en modo seguro.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="462"/>
        <source>Safe mode</source>
        <translation>Modo seguro</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="516"/>
        <source>Save to Pdf</source>
        <translation>Guardar en Pdf</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="516"/>
        <source>Pdf &amp; Ps files (*.pdf *.ps)</source>
        <translation>Archivos Pdf &amp; Ps (*.pdf *.ps)</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="523"/>
        <source>File saved at: %1</source>
        <translation>Archivo guardado en: %1</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="635"/>
        <source>Select a file</source>
        <translation>Seleccione un archivo</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="638"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="646"/>
        <source>Incorrect use of the EXPORT DATA FOR INSERT Option. Example: EXPORT DATA FOR INSERT `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Exportar los datos de la tabla para INSERT. Ejemplo: EXPORT DATA FOR INSERT `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="558"/>
        <source>Incorrect use of the EXPLAIN SELECT Option. Example: SELECT * FROM `columns_pri`, it only works for the current database, the asterisk must be selected.</source>
        <translation>Uso incorrecto de la Opción Explicar SELECT. Ejemplo: SELECT * FROM `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="669"/>
        <source>Incorrect use of the EXPLAIN INSERT Option. Example: INSERT INTO `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Explicar INSERT. Ejemplo: INSERT INTO `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="797"/>
        <source>Incorrect use of the TRIM columns Option. Example: TRIM COLUMNS IN `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Recortar las columnas. Ejemplo: TRIM COLUMNS IN `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <source>Bad use of the EXPORT DATA FOR INSERT option.</source>
        <translation type="obsolete">Mal uso de la opción: Exportar los datos de la tabla para INSERT.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="682"/>
        <source>seconds</source>
        <translation>segundos</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="686"/>
        <location filename="../sqlquery.cpp" line="691"/>
        <source>minutes</source>
        <translation>minutos</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="693"/>
        <source>Elapsed: %1 %2. Remaining: %3 %4.
Total of queries: %5, remaining: %6.
Queries per second: %7.</source>
        <translation>Transcurrido: %1 %2. Restante: %3 %4.\nTotal de sentencias: %5, restantes: %6.\nConsultas por segundo: %7.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="749"/>
        <source>Incorrect use of the EXPLAIN UPDATE Option. Example: UPDATE `columns_pri`, it only works for the current database.</source>
        <translation>Uso incorrecto de la Opción Explicar UPDATE. Ejemplo: UPDATE `columns_pri`, solo funciona para la base de datos actual.</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="758"/>
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
        <location filename="../sqlquery.cpp" line="176"/>
        <source>Stop execution</source>
        <translation>Detener ejecución</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="178"/>
        <source>Run previous query</source>
        <translation>Ejecutar consulta previa</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="180"/>
        <source>Run next query</source>
        <translation>Ejecutar próxima consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="182"/>
        <source>Run first query</source>
        <translation>Ejecutar la primera consulta</translation>
    </message>
    <message>
        <location filename="../sqlquery.cpp" line="184"/>
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
        <location filename="../serverInformation.cpp" line="94"/>
        <source>Start time</source>
        <translation>Tiempo de inicio</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="95"/>
        <source>User</source>
        <translation>Usuario</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="96"/>
        <source>Time</source>
        <translation>Tiempo</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="97"/>
        <source>SQL Text</source>
        <translation>Texto SQL</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="331"/>
        <source>Server Information</source>
        <translation>Información del Servidor</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="334"/>
        <source>User:</source>
        <translation>Usuario:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="336"/>
        <source>Host:</source>
        <translation>Huésped:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="338"/>
        <source>Socket:</source>
        <translation>Socket:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="340"/>
        <source>Port:</source>
        <translation>Puerto:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="342"/>
        <source>Version:</source>
        <translation>Versión:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="344"/>
        <source>Connection id:</source>
        <translation>Id de la conexión:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="346"/>
        <source>Server status:</source>
        <translation>Estado del servidor:</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="347"/>
        <source>Connection</source>
        <translation>Conexión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="348"/>
        <source>Status</source>
        <translation>Estado</translation>
    </message>
    <message>
        <source>Refresh</source>
        <translation type="obsolete">Refrescar</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="352"/>
        <location filename="../serverInformation.cpp" line="359"/>
        <source>Replication Status</source>
        <translation>Estado del Replicador</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="353"/>
        <location filename="../serverInformation.cpp" line="362"/>
        <location filename="../serverInformation.cpp" line="367"/>
        <location filename="../serverInformation.cpp" line="370"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="354"/>
        <source>Skip 0</source>
        <translation>Saltar 0</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="355"/>
        <source>Skip 1</source>
        <translation>Saltar 1</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="356"/>
        <source>Skip 10</source>
        <translation>Saltar 10</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="357"/>
        <source>Skip 100</source>
        <translation>Saltar 100</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="358"/>
        <location filename="../serverInformation.cpp" line="364"/>
        <location filename="../serverInformation.cpp" line="368"/>
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
        <location filename="../serverInformation.cpp" line="360"/>
        <location filename="../serverInformation.cpp" line="361"/>
        <source>Variables</source>
        <translation>Variables</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="363"/>
        <location filename="../serverInformation.cpp" line="365"/>
        <location filename="../serverInformation.cpp" line="366"/>
        <location filename="../serverInformation.cpp" line="369"/>
        <location filename="../serverInformation.cpp" line="673"/>
        <source>Server Graphics</source>
        <translation>Gráficos del Servidor</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="371"/>
        <location filename="../serverInformation.cpp" line="372"/>
        <source>HDD Usage</source>
        <translation>Uso del HDD</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="374"/>
        <source>Filter</source>
        <translation>Filtro</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="375"/>
        <source>Show global variables</source>
        <translation>Mostrar variables globales</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="376"/>
        <source>Show global status</source>
        <translation>Mostrar el estado global</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="377"/>
        <source>Show session status</source>
        <translation>Mostrar estado de la sessión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="378"/>
        <source>Show session variables</source>
        <translation>Mostrar variables de sessión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="379"/>
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
        <location filename="../serverInformation.cpp" line="349"/>
        <source>Show server status</source>
        <translation>Mostrar estado del servidor</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="350"/>
        <source>Show slow queries</source>
        <translation>Mostrar las consultas lentas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="380"/>
        <source>Three characters at least</source>
        <translation>Tres caracteres como mínimo</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="381"/>
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
        <location filename="../serverInformation.cpp" line="414"/>
        <source>Data sent in MB.</source>
        <translation>Datos enviados en MB.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="416"/>
        <location filename="../serverInformation.cpp" line="430"/>
        <source>Transfer rate: %1 Kb per second.</source>
        <translation>Radio de transferencia: %1 Kb por segundo.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="428"/>
        <source>Data received in MB.</source>
        <translation>Datos recibidos e MB.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="433"/>
        <source>Miscellaneous values.</source>
        <translation>Valores miceláneos.</translation>
    </message>
    <message>
        <source>Other</source>
        <translation type="obsolete">Otros</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="386"/>
        <source>Enter the default connection name and press Enter.</source>
        <translation>Ingrese el nombre de la conexión predeterminada y presione Enter.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="531"/>
        <source>Database sizes description.</source>
        <translation>Descripción de los tamaños de las bases de datos.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="535"/>
        <location filename="../serverInformation.cpp" line="545"/>
        <source>Database</source>
        <translation>Base de Datos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="536"/>
        <location filename="../serverInformation.cpp" line="546"/>
        <source>Total</source>
        <translation>Total</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="537"/>
        <location filename="../serverInformation.cpp" line="547"/>
        <source>Data</source>
        <translation>Datos</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="538"/>
        <location filename="../serverInformation.cpp" line="548"/>
        <source>Indexes</source>
        <translation>Índices</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="539"/>
        <source>Tables</source>
        <translation>Tablas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="540"/>
        <location filename="../serverInformation.cpp" line="549"/>
        <source>Rows</source>
        <translation>Filas</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="544"/>
        <source>Detailed size table description. Table size greater than %1 MB.</source>
        <translation>Descripción detallada del tamaño de las tablas. Tamaño de tablas mayores a %1 MB.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="545"/>
        <source>Table name</source>
        <translation>Nombre de la tabla</translation>
    </message>
    <message>
        <source>Pending.</source>
        <translation type="obsolete">Pendiente.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="558"/>
        <location filename="../serverInformation.cpp" line="580"/>
        <source>There was an error determinating the DBMS type.</source>
        <translation>Hubo un error al determinar el tipo de DBMS.</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="569"/>
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
        <location filename="../serverInformation.cpp" line="574"/>
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
        <location filename="../serverInformation.cpp" line="655"/>
        <source>Global status</source>
        <translation>Estado global</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="657"/>
        <source>Session status</source>
        <translation>Estado de sesión</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="659"/>
        <source>Global variables</source>
        <translation>Variables globales</translation>
    </message>
    <message>
        <location filename="../serverInformation.cpp" line="661"/>
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
        <location filename="../staticfunctions.cpp" line="204"/>
        <source>Returns the absolute value of &lt;b&gt;X&lt;/b&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="207"/>
        <source>Adds expr2 to expr1 and returns the result.&lt;br /&gt;expr1 is a time or datetime expression, and expr2 is a time expression.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="214"/>
        <source>Returns the average value of expr.&lt;br /&gt;The DISTINCT option can be used as of MySQL 5.0.3 to return the average of the distinct values of expr.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="216"/>
        <source>Returns a string representation of the binary value of N.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="222"/>
        <source>Takes an expression of any type and produces a result value of a specified type.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="223"/>
        <location filename="../staticfunctions.cpp" line="224"/>
        <source>Returns the smallest integer value not less than X</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="225"/>
        <source>Returns the length of the string str, measured in characters. A multi-byte character counts as a single character.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="232"/>
        <source>Returns the string that results from concatenating the arguments.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="238"/>
        <source>Returns a count of the number of non-NULL values of expr in the rows retrieved by a SELECT statement.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="240"/>
        <location filename="../staticfunctions.cpp" line="241"/>
        <source>Returns the current date as a value in &apos;YYYY-MM-DD&apos; or YYYYMMDD format, depending on whether the function is used in a string or numeric context.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="243"/>
        <location filename="../staticfunctions.cpp" line="324"/>
        <source>Returns the current date and time as a value in &apos;YYYY-MM-DD HH:MM:SS&apos; or YYYYMMDDHHMMSS.uuuuuu format, &lt;br /&gt;depending on whether the function is used in a string or numeric context.&lt;br /&gt;The value is expressed in the current time zone.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="244"/>
        <source>Returns the user name and host name combination for the MySQL account that the server used to authenticate the current client.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="247"/>
        <source>Returns a string containing the date in the specified format.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="249"/>
        <source>Returns expr1 - expr2 expressed as a value in days from one date to the other.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="254"/>
        <source>Returns the name of the weekday for date.&lt;br /&gt;The language used for the name is controlled by the value of the lc_time_names system variable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="273"/>
        <source>Returns the largest integer value not greater than x.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="274"/>
        <source>Formats the number X to a format like &apos;#,###,###.##&apos;, rounded to D decimal places, and returns the result as a string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="277"/>
        <source>Returns a representation of the unix_timestamp argument as a value in &apos;YYYY-MM-DD HH:MM:SS&apos; or YYYYMMDDHHMMSS.uuuuuu format,&lt;br /&gt;depending on whether the function is used in a string or numeric context.&lt;br /&gt;If format is given, the result is formatted according to the format string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="281"/>
        <source>This function returns a string result with the concatenated non-NULL values from a group. It returns NULL if there are no non-NULL values.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="286"/>
        <source>If expr1 is not NULL, IFNULL() returns expr1; otherwise it returns expr2.&lt;br /&gt;IFNULL() returns a numeric or string value, depending on the context in which it is used.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="287"/>
        <source>Given the dotted-quad representation of an IPv4 network address as a string, returns an integer that represents the numeric value of the address in network byte order (big endian).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="288"/>
        <source>Given a numeric IPv4 network address in network byte order, returns the dotted-quad representation of the address as a binary string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="289"/>
        <source>Returns the position of the first occurrence of substring substr in string str.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="293"/>
        <source>If expr is NULL, ISNULL() returns 1, otherwise it returns 0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="296"/>
        <source>Returns the string str with all characters changed to lowercase according to the current character set mapping.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="299"/>
        <source>Returns the length of the string str, measured in bytes. &lt;br /&gt;A multi-byte character counts as multiple bytes.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="303"/>
        <source>Returns the position of the first occurrence of substring substr in string str, starting at position pos.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="307"/>
        <source>Returns the string str with all characters changed to lowercase according to the current character set mapping. </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="308"/>
        <source>Returns the string str, left-padded with the string padstr to a length of len characters.&lt;br /&gt;If str is longer than len, the return value is shortened to len characters.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="314"/>
        <source>Returns the maximum value of expr.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="315"/>
        <source>Calculates an MD5 128-bit checksum for the string. The value is returned as a string of 32 hex digits, or NULL if the argument was NULL.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="316"/>
        <source>Returns the microseconds from the time or datetime expression expr as a number in the range from 0 to 999999.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="317"/>
        <location filename="../staticfunctions.cpp" line="367"/>
        <location filename="../staticfunctions.cpp" line="369"/>
        <source>The forms without a len argument return a substring from string str starting at position pos. &lt;br /&gt;The forms with a len argument return a substring len characters long from string str, starting at position pos.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="318"/>
        <source>Returns the minimum value of expr.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="321"/>
        <source>Returns the month for date, in the range 1 to 12 for January to December.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="325"/>
        <source>Returns NULL if expr1 = expr2 is true, otherwise returns expr1.&lt;br /&gt;This is the same as CASE WHEN expr1 = expr2 THEN NULL ELSE expr1 END.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="340"/>
        <source>Returns a random floating-point value v in the range 0 &lt;= v &lt; 1.0. If a constant integer argument N is specified, it is used as the seed value, which produces a repeatable sequence of column values.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="345"/>
        <source>Returns the number of rows changed, deleted, or inserted by the last statement.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="346"/>
        <source>Returns the string str, right-padded with the string padstr to a length of len characters.&lt;br /&gt;If str is longer than len, the return value is shortened to len characters.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="348"/>
        <source>Returns the seconds argument, converted to hours, minutes, and seconds, as a TIME value.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="368"/>
        <source>Returns the substring from string str before count occurrences of the delimiter delim. &lt;br /&gt;If count is positive, everything to the left of the final delimiter (counting from the left) is returned. &lt;br /&gt;If count is negative, everything to the right of the final delimiter (counting from the right) is returned.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="246"/>
        <location filename="../staticfunctions.cpp" line="248"/>
        <source>These functions perform date arithmetic.&lt;br /&gt;The date argument specifies the starting date or datetime value.&lt;br /&gt;expr is an expression specifying the interval value to be added or subtracted from the starting date.&lt;br /&gt;expr is a string; it may start with a “-” for negative intervals.&lt;br /&gt;unit is a keyword indicating the units in which the expression should be interpreted.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="231"/>
        <source>Concatenate the strings with the given separator.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="233"/>
        <source>Returns the connection ID (thread ID) for the connection.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="295"/>
        <source>Returns a value representing the first automatically generated value successfully inserted for an AUTO_INCREMENT column as a result of the most recently executed INSERT statement.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="344"/>
        <source>Rounds the argument X to D decimal places.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="370"/>
        <source>Returns expr1 – expr2 expressed as a value in the same format as expr1.&lt;br /&gt;expr1 is a time or datetime expression, and expr2 is a time expression.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="375"/>
        <source>Returns the time argument, converted to seconds.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="376"/>
        <source>Returns expr1 - expr2 expressed as a time value.&lt;br /&gt;expr1 and expr2 are time or date-and-time expressions, but both must be of the same type.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="378"/>
        <source>Returns datetime_expr2 - datetime_expr1, where datetime_expr1 and datetime_expr2 are date or datetime expressions.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="379"/>
        <source>Returns a day number (the number of days since year 0).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="380"/>
        <source>Returns the string str with all remstr prefixes or suffixes removed.&lt;br /&gt;If none of the specifiers BOTH, LEADING, or TRAILING is given, BOTH is assumed. remstr is optional and, if not specified, spaces are removed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="381"/>
        <source>Returns the number X, truncated to D decimal places.&lt;br /&gt;If D is 0, the result has no decimal point or fractional part.&lt;br /&gt;D can be negative to cause D digits left of the decimal point of the value X to become zero.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="382"/>
        <source>Returns the string str with all characters changed to uppercase according to the current character set mapping.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="386"/>
        <source>If called with no argument, returns a Unix timestamp (seconds since &apos;1970-01-01 00:00:00&apos; UTC) as an unsigned integer.&lt;br /&gt;If UNIX_TIMESTAMP() is called with a date argument, it returns the value of the argument as seconds since &apos;1970-01-01 00:00:00&apos; UTC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="389"/>
        <source>Returns the current MySQL user name and host name.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="397"/>
        <source>Returns a string that indicates the MySQL server version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="404"/>
        <source>If expr is greater than or equal to min and expr is less than or equal to max, BETWEEN returns 1, otherwise it returns 0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1218"/>
        <source>Quote string with slashes</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1276"/>
        <source>Create an array</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1281"/>
        <source>Compares array1 against array2 and returns the difference.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1286"/>
        <source>Fills an array with num entries of the value of the value parameter, keys starting at the start_index parameter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1288"/>
        <source>Filters elements of an array using a callback function.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1289"/>
        <source>Exchanges all keys with their associated values in an array.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1296"/>
        <source>Returns the keys, numeric and string, from the input array.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1297"/>
        <source>Applies the callback to the elements of the given arrays.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1298"/>
        <source>Merge one or more arrays.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1302"/>
        <source>Pop the element off the end of array</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1310"/>
        <source>Searches the array for a given value and returns the corresponding key if successful.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1312"/>
        <source>Extract a slice of the array</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1313"/>
        <source>Remove a portion of the array and replace it with something else</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1314"/>
        <source>Calculate the sum of values in an array.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1323"/>
        <source>Return all the values of an array.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1329"/>
        <source>Sort an array in reverse order and maintain index association</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1332"/>
        <source>Sort an array and maintain index association.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1340"/>
        <source>Decodes data encoded with MIME base64.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1341"/>
        <source>Encodes data with MIME base64</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1533"/>
        <source>Calls the callback given by the first parameter and passes the remaining parameters as arguments.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1550"/>
        <source>Split a string into smaller chunks</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1564"/>
        <source>Close directory handle</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1599"/>
        <source>Counts all elements in an array, or something in an object.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1739"/>
        <source>Format a local time/date</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1905"/>
        <source>Generates a backtrace.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1911"/>
        <source>Defines a named constant</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="1929"/>
        <source>Returns parent directory&apos;s path</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2043"/>
        <source>Output one or more strings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2100"/>
        <source>Determine whether a variable is empty</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2128"/>
        <source>Sets which PHP errors are reported.&lt;br /&gt;E_ERROR, E_WARNING, E_PARSE, E_NOTICE, E_CORE_ERROR&lt;br /&gt;, E_CORE_WARNING, E_COMPILE_ERROR, E_COMPILE_WARNING, E_USER_ERROR, E_USER_WARNING&lt;br /&gt;, E_USER_NOTICE, E_STRICT, E_RECOVERABLE_ERROR, E_DEPRECATED, E_USER_DEPRECATED, E_ALL</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2166"/>
        <source>Split a string by string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2243"/>
        <source>Closes an open file pointer</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2285"/>
        <source>Reads entire file into an array</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2286"/>
        <source>Checks whether a file or directory exists</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2287"/>
        <source>Reads entire file into a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2288"/>
        <source>Write a string to a file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2303"/>
        <source>Gets file size</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2311"/>
        <source>Filters a variable with a specified filter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2325"/>
        <source>Opens file or URL</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2332"/>
        <source>Binary-safe file read</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2379"/>
        <source>Checks the list of defined functions, both built-in (internal) and user-defined, for function_name.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2380"/>
        <source>Binary-safe file write.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="2812"/>
        <source>Send a raw HTTP header</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3900"/>
        <source>Join array elements with a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3902"/>
        <source>Searches haystack for needle using loose Comparision unless strict is set.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3903"/>
        <source>Includes and evaluates the specified file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3904"/>
        <source>Includes and evaluates the specified file during the execution of the script</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3947"/>
        <source>Sets the value of a configuration option.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3968"/>
        <source>Finds whether a variable is an array.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3971"/>
        <source>Tells whether the filename is a directory</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3983"/>
        <source>Finds whether a variable is NULL</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="3984"/>
        <source>Finds whether a variable is a number or a numeric string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4005"/>
        <source>Determine if a variable is set and is not NULL</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4027"/>
        <source>Decodes a JSON string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4046"/>
        <source>Sort an array by key in reverse order</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4047"/>
        <source>Sort an array by key</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4169"/>
        <source>Send mail</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4378"/>
        <source>Calculate the md5 hash of a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4394"/>
        <source> Return current Unix timestamp with microseconds.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4545"/>
        <source>Generate a better random value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4943"/>
        <source>Format a number with grouped thousands</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4956"/>
        <source>Get current buffer contents and delete current output buffer.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="4967"/>
        <source>Turn on output buffering.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5163"/>
        <source>Open directory handle</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5246"/>
        <source>Parse a URL and return its components.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5553"/>
        <source>Gets the current PHP version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5598"/>
        <source>Searches subject for a match to the regular expression given in pattern.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5601"/>
        <source>Perform a regular expression search and replace.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5606"/>
        <source>Prints human-readable information about a variable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5813"/>
        <source>Read entry from directory handle</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5814"/>
        <source>Outputs a file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5861"/>
        <source>Includes and evaluates the specified file. Halt the script whereas include() emits a warning</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5862"/>
        <source>Identical to require() except PHP will check if the file has already been included, and if so, not include (require) it again</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5872"/>
        <source>Rounds a float</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="5895"/>
        <source>Strip whitespace (or other characters) from the end of a string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6016"/>
        <source>Generates a storable representation of a value.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6051"/>
        <source>Limits the maximum execution time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6061"/>
        <source>Execute command via shell and return the complete output as a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6167"/>
        <source>This function sorts an array. Elements will be arranged from lowest to highest when this function has completed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6383"/>
        <source>Replace all occurrences of the search string with the replacement string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6445"/>
        <source>Get string length</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6451"/>
        <source>Find the position of the first occurrence of a substring in a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6462"/>
        <source>Make a string uppercase.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6465"/>
        <source>Return part of a string</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6468"/>
        <source>Replace text within a portion of a string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6811"/>
        <source>Return current Unix timestamp</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6835"/>
        <source>Strip whitespace (or other characters) from the beginning and end of a string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6838"/>
        <source>Uppercase the first character of each word in a string.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6867"/>
        <source>Generate a unique ID</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6872"/>
        <source>Creates a PHP value from a stored representation.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6873"/>
        <source>Unset a given variable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6879"/>
        <source>Sort an array by values using a user-defined Comparision function</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6880"/>
        <source>Converts a string with ISO-8859-1 characters encoded with UTF-8 to single-byte ISO-8859-1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="6884"/>
        <source>Dumps information about a variable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7375"/>
        <source>A rule that allows websites to download and use fonts other than the &apos;web-safe&apos; fonts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7376"/>
        <source>Specifies the animation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7377"/>
        <source>Allows more precise alignment of elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7378"/>
        <source>Specifies how an inline-level element is aligned with respect to its parent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7379"/>
        <source>A shorthand property for all the animation properties below, except the animation-play-state property</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7380"/>
        <source>Specifies when the animation will start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7381"/>
        <source>Specifies whether or not the animation should play in reverse on alternate cycles</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7382"/>
        <source>Specifies how many seconds or milliseconds an animation takes to complete one cycle</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7383"/>
        <source>Specifies the number of times an animation should be played</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7384"/>
        <source>Specifies a name for the @keyframes animation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7385"/>
        <source>Specifies whether the animation is running or paused</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7386"/>
        <source>Specifies the speed curve of the animation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7387"/>
        <source>Allows you to make an element look like a standard user interface element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7388"/>
        <source>Defines whether or not an element should be visible when not facing the screen</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7389"/>
        <source>Sets all the background properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7390"/>
        <source>Sets whether a background image is fixed or scrolls with the rest of the page</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7391"/>
        <source>Specifies the painting area of the background</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7392"/>
        <source>Sets the background color of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7393"/>
        <source>Sets the background image for an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7394"/>
        <source>Specifies the positioning area of the background images</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7395"/>
        <source>Sets the starting position of a background image</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7396"/>
        <source>Sets how a background image will be repeated</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7397"/>
        <source>Specifies the size of the background images</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7398"/>
        <source>Allows repositioning of the dominant-baseline relative to the dominant-baseline</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7399"/>
        <source>Specifies the label of the bookmark</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7400"/>
        <source>Specifies the level of the bookmark</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7401"/>
        <source>Specifies the target of the bookmark link</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7402"/>
        <source>Sets all the border properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7403"/>
        <source>Sets all the bottom border properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7404"/>
        <source>Sets the color of the bottom border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7405"/>
        <source>Defines the shape of the border of the bottom-left corner</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7406"/>
        <source>Defines the shape of the border of the bottom-right corner</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7407"/>
        <source>Sets the style of the bottom border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7408"/>
        <source>Sets the width of the bottom border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7409"/>
        <source>Specifies whether or not table borders should be collapsed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7410"/>
        <source>Sets the color of the four borders</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7411"/>
        <source>A shorthand property for setting all the border-image-* properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7412"/>
        <source>Specifies the amount by which the border image area extends beyond the border box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7413"/>
        <source>Specifies whether the image-border should be repeated, rounded or stretched</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7414"/>
        <source>Specifies the inward offsets of the image-border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7415"/>
        <source>Specifies an image to be used as a border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7416"/>
        <source>Specifies the widths of the image-border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7417"/>
        <source>Sets all the left border properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7418"/>
        <source>Sets the color of the left border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7419"/>
        <source>Sets the style of the left border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7420"/>
        <source>Sets the width of the left border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7421"/>
        <source>A shorthand property for setting all the four border-*-radius properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7422"/>
        <source>Sets all the right border properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7423"/>
        <source>Sets the color of the right border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7424"/>
        <source>Sets the style of the right border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7425"/>
        <source>Sets the width of the right border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7426"/>
        <source>Specifies the distance between the borders of adjacent cells</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7427"/>
        <source>Sets the style of the four borders</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7428"/>
        <source>Sets all the top border properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7429"/>
        <source>Sets the color of the top border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7430"/>
        <source>Defines the shape of the border of the top-left corner</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7431"/>
        <source>Defines the shape of the border of the top-right corner</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7432"/>
        <source>Sets the style of the top border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7433"/>
        <source>Sets the width of the top border</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7434"/>
        <source>Sets the width of the four borders</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7435"/>
        <source>Specifies the bottom position of a positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7436"/>
        <source>Specifies how to align the child elements of a box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7437"/>
        <location filename="../staticfunctions.cpp" line="7577"/>
        <location filename="../staticfunctions.cpp" line="7603"/>
        <source> </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7438"/>
        <source>Specifies in which direction the children of a box are displayed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7439"/>
        <source>Specifies whether the children of a box is flexible or inflexible in size</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7440"/>
        <source>Assigns flexible elements to flex groups</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7441"/>
        <source>Specifies whether columns will go onto a new line whenever it runs out of space in the parent box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7442"/>
        <source>Specifies the display order of the child elements of a box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7443"/>
        <source>Specifies whether the children of a box should be laid out horizontally or vertically</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7444"/>
        <source>Specifies the horizontal position in horizontal boxes and the vertical position in vertical boxes</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7445"/>
        <source>Attaches one or more drop-shadows to the box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7446"/>
        <source>Allows you to define certain elements to fit an area in a certain way</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7447"/>
        <source>Specifies the placement of a table caption</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7448"/>
        <source>Specifies which sides of an element where other floating elements are not allowed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7449"/>
        <source>Clips an absolutely positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7450"/>
        <source>Sets the color of text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7451"/>
        <source>Permits the specification of a source color profile other than the default</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7452"/>
        <source>Specifies the number of columns an element should be divided into</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7453"/>
        <source>Specifies how to fill columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7454"/>
        <source>Specifies the gap between the columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7455"/>
        <source>A shorthand property for setting all the column-rule-* properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7456"/>
        <source>Specifies the color of the rule between columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7457"/>
        <source>Specifies the style of the rule between columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7458"/>
        <source>Specifies the width of the rule between columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7459"/>
        <source>Specifies how many columns an element should span across</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7460"/>
        <source>Specifies the width of the columns</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7461"/>
        <source>A shorthand property for setting column-width and column-count</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7462"/>
        <source>Used with the :before and :after pseudo-elements, to insert generated content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7463"/>
        <source>Increments one or more counters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7464"/>
        <source>Creates or resets one or more counters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7465"/>
        <source>Allows a replaced element to be just a rectangular area of an object, instead of the whole object</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7466"/>
        <source>Specifies the type of cursor to be displayed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7467"/>
        <source>Specifies the text direction/writing direction</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7468"/>
        <source>Specifies how a certain HTML element should be displayed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7469"/>
        <source>Specifies a scaled-baseline-table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7470"/>
        <source>Sets the alignment point of the drop initial for the primary connection point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7471"/>
        <source>Sets which alignment line within the initial line box is used at the primary connection point with the initial letter box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7472"/>
        <source>Sets the alignment point of the drop initial for the secondary connection point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7473"/>
        <source>Sets which alignment line within the initial line box is used at the secondary connection point with the initial letter box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7474"/>
        <source>Controls the partial sinking of the initial letter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7475"/>
        <source>Activates a drop-initial effect</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7476"/>
        <source>Specifies whether or not to display borders and background on empty cells in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7477"/>
        <source>Gives a hint for how to scale a replaced element if neither its width nor its height property is auto</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7478"/>
        <source>Determines the alignment of the object inside the box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7479"/>
        <source>Specifies whether or not a box should float</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7480"/>
        <source>Pushes floated elements in the opposite direction of the where they have been floated with float</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7481"/>
        <source>Sets all the font properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7482"/>
        <source>Specifies the font family for text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7483"/>
        <source>Specifies the font size of text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7484"/>
        <source>Preserves the readability of text when font fallback occurs</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7485"/>
        <source>Selects a normal, condensed, or expanded face from a font family</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7486"/>
        <source>Specifies the font style for text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7487"/>
        <source>Specifies whether or not a text should be displayed in a small-caps font</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7488"/>
        <source>Specifies the weight of a font</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7489"/>
        <source>Specifies the width of each column in a grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7490"/>
        <source>Specifies the height of each column in a grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7491"/>
        <source>Specifies whether a punctuation character may be placed outside the line box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7492"/>
        <source>Sets the height of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7493"/>
        <source>Specifies the minimum number of characters in a hyphenated word after the hyphenation character</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7494"/>
        <source>Specifies the minimum number of characters in a hyphenated word before the hyphenation character</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7495"/>
        <source>Specifies a string that is shown when a hyphenate-break occurs</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7496"/>
        <source>Indicates the maximum number of successive hyphenated lines in an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7497"/>
        <source>Specifies a comma-separated list of external resources that can help the browser determine hyphenation points</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7498"/>
        <source>Sets how to split words to improve the layout of paragraphs</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7499"/>
        <source>Provides the author the ability to style an element with an iconic equivalent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7500"/>
        <source>Specifies a rotation in the right or clockwise direction that a user agent applies to an image</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7501"/>
        <source>Specifies the correct resolution of images</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7502"/>
        <source>Sets which line of a multi-line inline block align with the previous and next inline elements within a line</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7503"/>
        <source>Specifies the left position of a positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7504"/>
        <source>Increases or decreases the space between characters in a text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7505"/>
        <source>Sets the line height</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7506"/>
        <source>A shorthand property for setting the line-stacking-strategy, line-stacking-ruby, and line-stacking-shift properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7507"/>
        <source>Sets the line stacking method for block elements containing ruby annotation elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7508"/>
        <source>Sets the line stacking method for block elements containing elements with base-shift</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7509"/>
        <source>Sets the line stacking strategy for stacked line boxes within a containing block element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7510"/>
        <source>Sets all the properties for a list in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7511"/>
        <source>Specifies an image as the list-item marker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7512"/>
        <source>Specifies if the list-item markers should appear inside or outside the content flow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7513"/>
        <source>Specifies the type of list-item marker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7514"/>
        <source>Sets all the margin properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7515"/>
        <source>Sets the bottom margin of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7516"/>
        <source>Sets the left margin of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7517"/>
        <source>Sets the right margin of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7518"/>
        <source>Sets the top margin of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7519"/>
        <source>A shorthand property for setting the mark-before and mark-after properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7520"/>
        <location filename="../staticfunctions.cpp" line="7521"/>
        <source>Allows named markers to be attached to the audio stream</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7522"/>
        <source>Adds crop and/or cross marks to the document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7523"/>
        <source>Sets the direction of the moving content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7524"/>
        <source>Sets how many times the content move</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7525"/>
        <source>Sets how fast the content scrolls</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7526"/>
        <source>Sets the style of the moving content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7527"/>
        <source>Sets the maximum height of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7528"/>
        <source>Sets the maximum width of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7529"/>
        <source>Sets the minimum height of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7530"/>
        <source>Sets the minimum width of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7531"/>
        <source>Causes an element to be removed from the flow and reinserted at a later point in the document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7532"/>
        <source>Specifies where to navigate when using the arrow-down navigation key</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7533"/>
        <source>Specifies the tabbing order for an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7534"/>
        <source>Specifies where to navigate when using the arrow-left navigation key</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7535"/>
        <source>Specifies where to navigate when using the arrow-right navigation key</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7536"/>
        <source>Specifies where to navigate when using the arrow-up navigation key</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7537"/>
        <source>Sets the opacity level for an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7538"/>
        <source>Sets the minimum number of lines that must be left at the bottom of a page when a page break occurs inside an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7539"/>
        <source>Sets all the outline properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7540"/>
        <source>Sets the color of an outline</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7541"/>
        <source>Offsets an outline, and draws it beyond the border edge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7542"/>
        <source>Sets the style of an outline</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7543"/>
        <source>Sets the width of an outline</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7544"/>
        <source>Specifies what happens if content overflows an element&apos;s box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7545"/>
        <source>Specifies the preferred scrolling method for elements that overflow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7546"/>
        <source>Specifies whether or not to clip the left/right edges of the content, if it overflows the element&apos;s content area</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7547"/>
        <source>Specifies whether or not to clip the top/bottom edges of the content, if it overflows the element&apos;s content area</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7548"/>
        <source>Sets all the padding properties in one declaration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7549"/>
        <source>Sets the bottom padding of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7550"/>
        <source>Sets the left padding of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7551"/>
        <source>Sets the right padding of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7552"/>
        <source>Sets the top padding of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7553"/>
        <source>Specifies a particular type of page where an element SHOULD be displayed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7554"/>
        <source>Sets the page-breaking behavior after an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7555"/>
        <source>Sets the page-breaking behavior before an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7556"/>
        <source>Sets the page-breaking behavior inside an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7557"/>
        <source>Determines which page-based occurance of a given element is applied to a counter or string value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7558"/>
        <source>Specifies the perspective on how 3D elements are viewed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7559"/>
        <source>Specifies the bottom position of 3D elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7560"/>
        <source>Specifies a phonetic pronunciation for the text contained by the corresponding element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7561"/>
        <source>Specifies the type of positioning method used for an element (static, relative, absolute or fixed)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7562"/>
        <source>Specifies whether a punctuation character should be trimmed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7563"/>
        <source>Sets the type of quotation marks for embedded quotations</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7564"/>
        <source>Permits the specification of a color profile rendering intent other than the default</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7565"/>
        <source>Specifies whether or not an element is resizable by the user</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7566"/>
        <source>A shorthand property for setting the rest-before and rest-after properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7567"/>
        <source>Specifies a rest or prosodic boundary to be observed after speaking an element&apos;s content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7568"/>
        <source>Specifies a rest or prosodic boundary to be observed before speaking an element&apos;s content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7569"/>
        <source>Specifies the right position of a positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7570"/>
        <source>Rotates an element around a given point defined by the rotation-point property</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7571"/>
        <source>Defines a point as an offset from the top left border edge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7572"/>
        <source>Controls the text alignment of the ruby text and ruby base contents relative to each other</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7573"/>
        <source>Determines whether, and on which side, ruby text is allowed to partially overhang any adjacent text in addition to its own base, when the ruby text is wider than the ruby base</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7574"/>
        <source>Controls the position of the ruby text with respect to its base</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7575"/>
        <source>Controls the spanning behavior of annotation elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7576"/>
        <source>Specifies the size and orientation of the containing box for page content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7578"/>
        <source>Sets the layout algorithm to be used for a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7579"/>
        <source>A shorthand property for setting the target-name, target-new, and target-position properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7580"/>
        <source>Specifies where to open links (target destination)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7581"/>
        <source>Specifies whether new destination links should open in a new window or in a new tab of an existing window</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7582"/>
        <source>Specifies where new destination links should be placed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7583"/>
        <source>Specifies the horizontal alignment of text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7584"/>
        <source>Describes how the last line of a block or a line right before a forced line break is aligned when text-align is &apos;justify&apos;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7585"/>
        <source>Specifies the decoration added to text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7586"/>
        <source>Sets the block-progression dimension of the text content area of an inline box</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7587"/>
        <source>Specifies the indentation of the first line in a text-block</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7588"/>
        <source>Specifies the justification method used when text-align is &apos;justify&apos;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7589"/>
        <source>Specifies a text outline</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7590"/>
        <source>Specifies what should happen when text overflows the containing element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7591"/>
        <source>Adds shadow to text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7592"/>
        <source>Controls the capitalization of text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7593"/>
        <source>Specifies line breaking rules for text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7594"/>
        <source>Specifies the top position of a positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7595"/>
        <source>Applies a 2D or 3D transformation to an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7596"/>
        <source>Allows you to change the position on transformed elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7597"/>
        <source>Specifies how nested elements are rendered in 3D space</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7598"/>
        <source>A shorthand property for setting the four transition properties</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7599"/>
        <source>Specifies when the transition effect will start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7600"/>
        <source>Specifies how many seconds or milliseconds a transition effect takes to complete</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7601"/>
        <source>Specifies the name of the CSS property the transition effect is for</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7602"/>
        <source>Specifies the speed curve of the transition effect</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7604"/>
        <source>Sets the vertical alignment of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7605"/>
        <source>Specifies whether or not an element is visible</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7606"/>
        <source>Specifies the balance between left and right channels</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7607"/>
        <source>Specifies how long it should take to render the selected element&apos;s content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7608"/>
        <source>Specifies the average pitch (a frequency) of the speaking voice</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7609"/>
        <source>Specifies variation in average pitch</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7610"/>
        <source>Controls the speaking rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7611"/>
        <source>Indicates the strength of emphasis to be applied</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7612"/>
        <source>Refers to the amplitude of the waveform output by the speech synthesises</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7613"/>
        <source>Specifies how white-space inside an element is handled</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7614"/>
        <source>Sets the minimum number of lines that must be left at the top of a page when a page break occurs inside an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7615"/>
        <source>Sets the width of an element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7616"/>
        <source>Specifies line breaking rules for non-CJK scripts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7617"/>
        <source>Increases or decreases the space between words in a text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7618"/>
        <source>Allows long, unbreakable words to be broken and wrap to the next line</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="7619"/>
        <source>Sets the stack order of a positioned element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8062"/>
        <source>Defines the document type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8063"/>
        <source>Defines a hyperlink</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8064"/>
        <source>Defines an abbreviation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8065"/>
        <source>Not supported in HTML5. Defines an acronym</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8066"/>
        <source>Defines contact information for the author/owner of a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8067"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Defines an embedded applet</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8068"/>
        <source>Defines an area inside an image-map</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8069"/>
        <source>Defines an article</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8070"/>
        <source>Defines content aside from the page content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8071"/>
        <source>Defines sound content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8072"/>
        <source>Defines bold text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8073"/>
        <source>Specifies the base URL/target for all relative URLs in a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8074"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Specifies a default color, size, and font for all text in a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8075"/>
        <source>Isolates a part of text that might be formatted in a different direction from other text outside it</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8076"/>
        <source>Overrides the current text direction</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8077"/>
        <source>Not supported in HTML5. Defines big text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8078"/>
        <source>Defines a section that is quoted from another source</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8079"/>
        <source>Defines the document&apos;s body</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8080"/>
        <source>Defines a single line break</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8081"/>
        <source>Defines a clickable button</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8082"/>
        <source>Used to draw graphics, on the fly, via scripting (usually JavaScript)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8083"/>
        <source>Defines a table caption</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8084"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Defines centered text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8085"/>
        <source>Defines the title of a work</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8086"/>
        <source>Defines a piece of computer code</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8087"/>
        <source>Specifies column properties for each column within a &lt;colgroup&gt; element </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8088"/>
        <source>Specifies a group of one or more columns in a table for formatting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8089"/>
        <source>Defines a command button that a user can invoke</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8090"/>
        <source>Specifies a list of pre-defined options for input controls</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8091"/>
        <source>Defines a description of an item in a definition list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8092"/>
        <source>Defines text that has been deleted from a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8093"/>
        <source>Defines additional details that the user can view or hide</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8094"/>
        <source>Defines a definition term</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8095"/>
        <source>Defines a dialog box or window</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8096"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Defines a directory list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8097"/>
        <location filename="../staticfunctions.cpp" line="8157"/>
        <location filename="../staticfunctions.cpp" line="8161"/>
        <source>Defines a section in a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8098"/>
        <source>Defines a definition list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8099"/>
        <source>Defines a term (an item) in a definition list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8100"/>
        <source>Defines emphasized text </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8101"/>
        <source>Defines a container for an external (non-HTML) application</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8102"/>
        <source>Groups related elements in a form</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8103"/>
        <source>Defines a caption for a &lt;figure&gt; element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8104"/>
        <source>Specifies self-contained content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8105"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Defines font, color, and size for text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8106"/>
        <source>Defines a footer for a document or section</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8107"/>
        <source>Defines an HTML form for user input</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8108"/>
        <source>Not supported in HTML5. Defines a window (a frame) in a frameset</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8109"/>
        <source>Not supported in HTML5. Defines a set of frames</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8110"/>
        <location filename="../staticfunctions.cpp" line="8111"/>
        <location filename="../staticfunctions.cpp" line="8112"/>
        <location filename="../staticfunctions.cpp" line="8113"/>
        <location filename="../staticfunctions.cpp" line="8114"/>
        <location filename="../staticfunctions.cpp" line="8115"/>
        <location filename="../staticfunctions.cpp" line="8116"/>
        <source>Defines HTML headings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8117"/>
        <source>Defines information about the document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8118"/>
        <source>Defines a header for a document or section</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8119"/>
        <source>Groups heading (&lt;h1&gt; to &lt;h6&gt;) elements</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8120"/>
        <source>Defines a thematic change in the content</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8121"/>
        <source>Defines the root of an HTML document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8122"/>
        <source>Defines a part of text in an alternate voice or mood</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8123"/>
        <source>Defines an inline frame</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8124"/>
        <source>Defines an image</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8125"/>
        <source>Defines an input control</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8126"/>
        <source>Defines a text that has been inserted into a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8127"/>
        <source>Defines keyboard input</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8128"/>
        <source>Defines a key-pair generator field (for forms)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8129"/>
        <source>Defines a label for an &lt;input&gt; element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8130"/>
        <source>Defines a caption for a &lt;fieldset&gt;, &lt; figure&gt;, or &lt;details&gt; element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8131"/>
        <source>Defines a list item</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8132"/>
        <source>Defines the relationship between a document and an external resource (most used to link to style sheets)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8133"/>
        <source>Defines a client-side image-map</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8134"/>
        <source>Defines marked/highlighted text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8135"/>
        <source>Defines a list/menu of commands</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8136"/>
        <source>Defines metadata about an HTML document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8137"/>
        <source>Defines a scalar measurement within a known range (a gauge)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8138"/>
        <source>Defines navigation links</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8139"/>
        <source>Not supported in HTML5. Defines an alternate content for users that do not support frames</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8140"/>
        <source>Defines an alternate content for users that do not support client-side scripts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8141"/>
        <source>Defines an embedded object</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8142"/>
        <source>Defines an ordered list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8143"/>
        <source>Defines a group of related options in a drop-down list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8144"/>
        <source>Defines an option in a drop-down list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8145"/>
        <source>Defines the result of a calculation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8146"/>
        <source>Defines a paragraph</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8147"/>
        <source>Defines a parameter for an object</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8148"/>
        <source>Defines preformatted text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8149"/>
        <source>Represents the progress of a task</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8150"/>
        <source>Defines a short quotation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8151"/>
        <source>Defines what to show in browsers that do not support ruby annotations</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8152"/>
        <source>Defines an explanation/pronunciation of characters (for East Asian typography)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8153"/>
        <source>Defines a ruby annotation (for East Asian typography)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8154"/>
        <source>Defines text that is no longer correct</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8155"/>
        <source>Defines sample output from a computer program</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8156"/>
        <source>Defines a client-side script</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8158"/>
        <source>Defines a drop-down list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8159"/>
        <source>Defines smaller text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8160"/>
        <source>Defines multiple media resources for media elements (&lt;video&gt; and &lt;audio&gt;)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8162"/>
        <source>Not supported in HTML5. Deprecated in HTML 4.01. Defines strikethrough text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8163"/>
        <source>Defines important text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8164"/>
        <source>Defines style information for a document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8165"/>
        <source>Defines subscripted text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8166"/>
        <source>Defines a visible heading for a &lt;details&gt; element</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8167"/>
        <source>Defines superscripted text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8168"/>
        <source>Defines a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8169"/>
        <source>Groups the body content in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8170"/>
        <source>Defines a cell in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8171"/>
        <source>Defines a multiline input control (text area)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8172"/>
        <source>Groups the footer content in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8173"/>
        <source>Defines a header cell in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8174"/>
        <source>Groups the header content in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8175"/>
        <source>Defines a date/time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8176"/>
        <source>Defines a title for the document</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8177"/>
        <source>Defines a row in a table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8178"/>
        <source>Defines text tracks for media elements (&lt;video&gt; and &lt;audio&gt;)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8179"/>
        <source>Not supported in HTML5. Defines teletype text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8180"/>
        <source>Defines text that should be stylistically different from normal text</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8181"/>
        <source>Defines an unordered list</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8182"/>
        <source>Defines a variable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8183"/>
        <source>Defines a video or movie</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8184"/>
        <source>Defines a possible line-break</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8300"/>
        <source>Uptime in days</source>
        <translation>Tiempo encendido en días</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8300"/>
        <source>Variable</source>
        <translation>Variable</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8300"/>
        <source>Value</source>
        <translation>Valor</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8302"/>
        <source>Number of aborted client connections.</source>
        <translation>Número de conexiones de cliente abortados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8307"/>
        <source>Number of aborted client connections per day.</source>
        <translation>Número de conexiones de cliente abortados por día.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8309"/>
        <source>Number of failed server connection attempts.</source>
        <translation>Número de intentos de conexión fallidos servidor.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8311"/>
        <source>Aborted connections per day</source>
        <translation>Conexiones abortadas por día</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8314"/>
        <source>Number of failed server connection attempts per day.</source>
        <translation>Número de conexiones abortadas por día.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8316"/>
        <source>Number of ROLLBACK commands executed.</source>
        <translation>Número de comandos ROLLBACK ejecutados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8321"/>
        <source>Number of ROLLBACK commands executed every second.</source>
        <translation>Número de comandos ROLLBACK ejecutados cada segundo.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8323"/>
        <source>Number of statements executed by the server.</source>
        <translation>Número de sentencias ejecutadas por el servidor.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8325"/>
        <source>Number of on-disk temporary tables created.</source>
        <translation>Número de tablas temporales creadas en disco.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8327"/>
        <source>Amount of free query cache memory.</source>
        <translation>La cantidad de memoria libre para la caché de consultas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8329"/>
        <source>Number of joins which did not use an index. If not zero, you may need to check table indexes.</source>
        <translation>Número de joins que no utilizaron un índice. Si no es cero, puede que tenga que comprobar los índices de tablas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8335"/>
        <source>Number of queries which took longer than long_query_time to run.</source>
        <translation>Número de consultas que tardaron más de LONG_QUERY_TIME para terminar.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8343"/>
        <source>The maximum number of simultaneous client connections.</source>
        <translation>El número máximo permitido de conexiones de cliente simultáneas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8345"/>
        <source>Max number of connections ever open at the same time.</source>
        <translation>Número máximo de conexiones abiertas al mismo tiempo.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8347"/>
        <source>DELETE commands executed</source>
        <translation>Comandos DELETE ejecutados</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8347"/>
        <source>Number of DELETE commands executed.</source>
        <translation>Número de comandos DELETE ejectados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8349"/>
        <source>INSERT commands executed</source>
        <translation>Comandos INSERT ejecutados</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8349"/>
        <source>Number of INSERT commands executed.</source>
        <translation>Número de comandos INSERT ejectados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8351"/>
        <source>UPDATE commands executed</source>
        <translation>Comandos UPDATE ejecutados</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8351"/>
        <source>Number of UPDATE commands executed.</source>
        <translation>Número de comandos UPDATE ejectados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8353"/>
        <source>SELECT commands executed</source>
        <translation>Comandos SELECT ejecutados</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8353"/>
        <source>Number of SELECT commands executed.</source>
        <translation>Número de comandos SELECT ejectados.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8355"/>
        <source>Requests of the first index row</source>
        <translation>Solicitudes de la primera fila de índice</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8355"/>
        <source>Number of requests to read the first row from an index. A high value indicates many full index scans.</source>
        <translation>Número de peticiones para leer la primera fila de un índice. Un valor alto indica muchas exploraciones de índices completos.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8357"/>
        <source>Rate of SELECTs per full index scans</source>
        <translation>Tasa de SELECTs por exploraciones de índices completos</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8357"/>
        <source>Rate of SELECTs per full index scans. A value higher than 100 means you do more table scan than SELECTs.</source>
        <translation>Tasa de SELECTs por exploraciones de índices completos. Un valor superior a 100 significa hacer más exploración de tabla de SELECTs.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8359"/>
        <source>Read requests based on an index value</source>
        <translation>Solicitudes de lectura basadas en un valor de índice</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8359"/>
        <source>Number of row read requests based on an index value. A high value indicates indexes are regularly being used.</source>
        <translation>Solicitudes de lectura basadas en un valor de índice. Un valor alto indica que los índices se utilizan regularmente.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8361"/>
        <source>Wait timeout</source>
        <translation>Tiempo de espera</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8361"/>
        <source>Time in seconds that the server waits for a connection to become active before closing it.</source>
        <translation>Tiempo en segundos que el servidor espera que una conexión se active antes de cerrarla.</translation>
    </message>
    <message>
        <source>The number of days that the server has been up.</source>
        <translation type="obsolete">El número de días que el servidor ha estado en funcionamiento.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8300"/>
        <source>Description</source>
        <translation>Descripción</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8300"/>
        <source>Number of days the server has been running.</source>
        <translation>Número de días que el servidor ha estado funcionando.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8300"/>
        <source>Variable mame</source>
        <translation>Nombre de la variable</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8302"/>
        <source>Aborted clients</source>
        <translation>Clientes abortados</translation>
    </message>
    <message>
        <source>The number of connections that were aborted because the client died without closing the connection properly.</source>
        <translation type="obsolete">El número de conexiones que han sido abortadas debido a que el cliente murió sin cerrar la conexión correctamente.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8304"/>
        <source>Aborted clients per day</source>
        <translation>Clientes abortados por día</translation>
    </message>
    <message>
        <source>Rate of aborted clients per day.</source>
        <translation type="obsolete">Tasa de clientes abortados por día.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8309"/>
        <source>Aborted connections</source>
        <translation>Conexiones abortadas</translation>
    </message>
    <message>
        <source>The number of failed attempts to connect to the database server.</source>
        <translation type="obsolete">El número de intentos fallidos de conectarse al servidor de base de datos.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8316"/>
        <source>Executed rollbacks</source>
        <translation>Rollbacks ejecutados</translation>
    </message>
    <message>
        <source>The number of times each rollback statement has been executed.</source>
        <translation type="obsolete">El número de veces que cada sentencia de rollback se ha ejecutado.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8323"/>
        <source>Executed queries</source>
        <translation>Consultas ejecutadas</translation>
    </message>
    <message>
        <source>The number of statements executed by the server.</source>
        <translation type="obsolete">El número de sentencias ejecutadas por el servidor.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8318"/>
        <source>Rollbacks per second</source>
        <translation>Rollbacks por segundo</translation>
    </message>
    <message>
        <source>Rate of rollbacks per second.</source>
        <translation type="obsolete">Tasa de rollbacks por segundo.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8325"/>
        <source>Temporary disk tables created</source>
        <translation>Tablas temporales de disco creadas</translation>
    </message>
    <message>
        <source>The number of internal on-disk temporary tables created by the server while executing statements.</source>
        <translation type="obsolete">El número de tablas temporales en disco internas creadas por el servidor mientras ejecuta las sentencias.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8327"/>
        <source>Free cache memory</source>
        <translation>Memoria cache libre</translation>
    </message>
    <message>
        <source>The amount of free memory for the query cache.</source>
        <translation type="obsolete">La cantidad de memoria libre para la caché de consultas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8329"/>
        <source>Joins with full table scan</source>
        <translation>Joins con escaneo completo de tabla</translation>
    </message>
    <message>
        <source>The number of joins that perform table scans because they do not use indexes.</source>
        <translation type="obsolete">El número de joins que realizan escaneos de tablas porque que no utilizan índices.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8331"/>
        <source>Log slow queries</source>
        <translation>Guardar consultas lentas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8331"/>
        <source>Is the slow queries logging enabled?</source>
        <translation>¿Está el loggeo de consultas habilitado?</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8333"/>
        <source>Slow queries time in seconds</source>
        <translation>Tiempo de consultas lentas en segundos</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8333"/>
        <source>The number of seconds that determinate a slow query.</source>
        <translation>El número de segundos para determinar que una consulta es lenta.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8335"/>
        <source>Count of slow queries</source>
        <translation>Conteo de consultas lentas</translation>
    </message>
    <message>
        <source>The number of queries that have taken more than the allowed time.</source>
        <translation type="obsolete">El número de consultas que han tardado más que el tiempo permitido.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8337"/>
        <source>Idle connections</source>
        <translation>Conexiones inactivas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8337"/>
        <source>The number of connections that has been idle for more than 30 seconds.</source>
        <translation>El número de conexiones que ha estado inactivo durante más de 30 segundos.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8339"/>
        <source>Active connections</source>
        <translation>Conexiones activas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8339"/>
        <source>The number of connections that has been idle for less than 30 seconds.</source>
        <translation>El número de conexiones que ha estado inactivo durante menos de 30 segundos.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8341"/>
        <source>Total connections</source>
        <translation>Toral de conexiones</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8341"/>
        <source>The number of active connections on the server.</source>
        <translation>El número de conexiones activas en el servidor.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8343"/>
        <source>Max connections aviable</source>
        <translation>Cantidad máxima de conexiones disponibles</translation>
    </message>
    <message>
        <source>The maximum permitted number of simultaneous client connections.</source>
        <translation type="obsolete">El número máximo permitido de conexiones de cliente simultáneas.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8345"/>
        <source>Used connections</source>
        <translation>Conexiones usadas</translation>
    </message>
    <message>
        <source>The maximum number of connections that have been in use simultaneously since the server started.</source>
        <translation type="obsolete">El número máximo de conexiones que han sido utilizadas simultáneamente desde que el servidor se inició.</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8376"/>
        <source>Date</source>
        <translation>Fecha</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8376"/>
        <source>Day</source>
        <translation>Día</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8376"/>
        <source>Total queries</source>
        <translation>Total de consultas</translation>
    </message>
    <message>
        <location filename="../staticfunctions.cpp" line="8377"/>
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
        <location filename="../texteditor.cpp" line="251"/>
        <source>Recent files</source>
        <translation>Archivos recientes</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="252"/>
        <location filename="../texteditor.cpp" line="263"/>
        <source>Symbols</source>
        <translation>Símbolos</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="516"/>
        <source>Print Script</source>
        <translation>Imprimir Script</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="554"/>
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
        <location filename="../texteditor.cpp" line="284"/>
        <source>Cut line</source>
        <translation>Cortar línea</translation>
    </message>
    <message>
        <source>Explain SELECT</source>
        <translation type="obsolete">Explicar SELECT</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="317"/>
        <source>Show SQL Helpers in the completion</source>
        <translation>Mostar Ayudas de SQL en el completado</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="319"/>
        <source>Export to Pdf</source>
        <translation>Exportar a Pdf</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="320"/>
        <source>Export to Odt</source>
        <translation>Exportar a Odt</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="321"/>
        <source>Export to Html</source>
        <translation>Exportar a Html</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="322"/>
        <source>Export to Svg</source>
        <translation>Exportar a Svg</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="323"/>
        <source>Export to Image</source>
        <translation>Exportar a Imagen</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="324"/>
        <source>Toggle Comment</source>
        <translation>Intercambiar Comentarios</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="333"/>
        <source>Uppercase keywords</source>
        <translation>Hacer mayúsculas las palabras clave</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="334"/>
        <source>Lowercase keywords</source>
        <translation>Hacer minúsculas las palabras clave</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1269"/>
        <source>SQL Query: Save file...</source>
        <translation>Consulta SQL: Guardar archivo...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1272"/>
        <source>PHP Script: Save file...</source>
        <translation>Script PHP: Guardar archivo...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1275"/>
        <source>CSS File: Save file...</source>
        <translation>Archivo CSS: Guardar archivo...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1278"/>
        <source>HTML File: Save file...</source>
        <translation>Archivo HTML: Guardar archivo...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1281"/>
        <source>JavaScript Script: Save file...</source>
        <translation>Script JavaScript: Guardar archivo...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1475"/>
        <source>PHP files (*.php *.inc *.module)</source>
        <translation>Archivos PHP (*.php *.inc *.module)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="971"/>
        <location filename="../texteditor.cpp" line="1844"/>
        <source>Cannot write file %1:
%2.</source>
        <translation>No es posible escribir en el archivo %1:
%2.</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="255"/>
        <source>Edit Menu</source>
        <translation>Menú Editar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="256"/>
        <source>&amp;Export</source>
        <translation>&amp;Exportar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="253"/>
        <source>Sort by name</source>
        <translation>Ordenar por nombre</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="986"/>
        <location filename="../texteditor.cpp" line="1819"/>
        <location filename="../texteditor.cpp" line="1832"/>
        <location filename="../texteditor.cpp" line="1850"/>
        <location filename="../texteditor.cpp" line="1869"/>
        <location filename="../texteditor.cpp" line="1892"/>
        <source>File saved at: %1</source>
        <translation>Archivo guardado en: %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="264"/>
        <source>Clear</source>
        <translation>Limpiar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="265"/>
        <source>Open</source>
        <translation>Abrir</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="266"/>
        <source>Save</source>
        <translation>Guardar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="267"/>
        <source>Save as...</source>
        <translation>Guardar como...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="268"/>
        <source>Copy</source>
        <translation>Copiar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="269"/>
        <source>Cut</source>
        <translation>Cortar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="270"/>
        <source>Paste</source>
        <translation>Pegar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="271"/>
        <source>Undo</source>
        <translation>Deshacer</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="272"/>
        <source>Redo</source>
        <translation>Rehacer</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="273"/>
        <source>Word wrap</source>
        <translation>Ajuste de línea</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="274"/>
        <source>In</source>
        <translation>Acercar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="275"/>
        <source>Out</source>
        <translation>Aleajr</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="276"/>
        <source>Restore</source>
        <translation>Restaurar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="277"/>
        <source>Line...</source>
        <translation>Línea...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="278"/>
        <source>Select all</source>
        <translation>Seleccionar todo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="279"/>
        <source>Clear recent files</source>
        <translation>Limpiar archivos recientes</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="280"/>
        <source>Print...</source>
        <translation>Imprimir...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="281"/>
        <source>Reload file</source>
        <translation>Recargar archivo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="282"/>
        <source>Disable completion</source>
        <translation>Deshabilitar completado</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="283"/>
        <source>Show/Hide line numbers</source>
        <translation>Mostrar/Ocultar números de línea</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="285"/>
        <source>Version &amp;control</source>
        <translation>Control de &amp;versiones</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="289"/>
        <source>SQL Query %1</source>
        <translation>Consulta SQL %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="290"/>
        <source>Fill MariaDB Symbols</source>
        <translation>Llenar símbolos de MariaDB</translation>
    </message>
    <message>
        <source>Explain INSERT</source>
        <translation type="obsolete">Explicar INSERT</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="293"/>
        <source>Run PHP Script</source>
        <translation>Correr Script PHP</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="294"/>
        <source>Check PHP Syntax</source>
        <translation>Revisión de sintaxis PHP</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="295"/>
        <source>PHP Script %1</source>
        <translation>Script PHP %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="298"/>
        <source>CSS Script %1</source>
        <translation>Script CSS %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="301"/>
        <source>HTML Script %1</source>
        <translation>Script HTML %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="304"/>
        <source>JavaScript Script %1</source>
        <translation>Script JavaScript %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="307"/>
        <source>Text File %1</source>
        <translation>Archivo de Texto %1</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="325"/>
        <source>Highlight current line</source>
        <translation>Resaltar la línea actual</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="326"/>
        <source>Normal</source>
        <translation>Normal</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="327"/>
        <source>Vertical</source>
        <translation>Vertical</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="328"/>
        <source>Horizontal</source>
        <translation>Horizontal</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="329"/>
        <source>&amp;Show Symols</source>
        <translation>&amp;Mostrar Símbolos</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="330"/>
        <source>&amp;Normalize text</source>
        <translation>&amp;Normalizar texto</translation>
    </message>
    <message>
        <source>Insert licence template</source>
        <translation type="obsolete">Insertar plantilla de licencia</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1472"/>
        <source>SQL files (*.sql)</source>
        <translation>Archivos SQL (*.sql)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1525"/>
        <source>Zoom</source>
        <translation>Enfocar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1812"/>
        <source>Save to Pdf</source>
        <translation>Guardar en Pdf</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1812"/>
        <source>Pdf &amp; Ps files (*.pdf *.ps)</source>
        <translation>Archivos Pdf &amp; Ps (*.pdf *.ps)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1827"/>
        <source>Save to Odt</source>
        <translation>Guardar en Odt</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1827"/>
        <source>Odt files (*.odt)</source>
        <translation>Archivos Odt (*.odt)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1840"/>
        <source>Save to Html</source>
        <translation>Guardar en Html</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1840"/>
        <source>Html files (*.html *.htm)</source>
        <translation>Archivos Html (*.html *.htm)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1858"/>
        <source>Save to Svg</source>
        <translation>Guardar en Svg</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1858"/>
        <source>Svg files (*.svg)</source>
        <translation>Archivos Svg (*.svg)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1880"/>
        <source>Save to Image</source>
        <translation>Guardar en Imagen</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1880"/>
        <source>Image files (%1)</source>
        <translation>Archivos de imagen (%1)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="257"/>
        <source>&amp;File</source>
        <translation>&amp;Archivo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="258"/>
        <source>&amp;Edit</source>
        <translation>&amp;Editar</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="259"/>
        <source>&amp;Options</source>
        <translation>&amp;Opciones</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="260"/>
        <source>&amp;Subversion</source>
        <translation>&amp;Subversion</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="261"/>
        <source>&amp;View</source>
        <translation>&amp;Ver</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="262"/>
        <source>View</source>
        <translation>Ver</translation>
    </message>
    <message>
        <source>Tool bar</source>
        <translation type="obsolete">Barra de herramientas</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1291"/>
        <source>The document has been modified.</source>
        <translation>El documento ha sido modificado.</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1292"/>
        <source>Do you want to save the changes?</source>
        <translation>¿Desea guardar los cambios?</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1368"/>
        <source>Go To Line...</source>
        <translation>Ir a la Línea...</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1368"/>
        <source>Line number</source>
        <translation>Número de línea</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1478"/>
        <source>CSS files (*.css)</source>
        <translation>Archivos CSS (*.css)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1481"/>
        <source>HTML files (*.html *.htm)</source>
        <translation>Archivos HTML (*.html *.htm)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1484"/>
        <source>JavaScript files (*.js)</source>
        <translation>Archivos JavaScript (*.js)</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1498"/>
        <source>Open a file</source>
        <translation>Abrir un archivo</translation>
    </message>
    <message>
        <location filename="../texteditor.cpp" line="1506"/>
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
