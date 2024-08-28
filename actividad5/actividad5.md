# Investigación sobre Conceptos de Sistemas Operativos

## Tipos de Kernel y sus Diferencias

### 1. Kernel Monolítico

El kernel monolítico es un tipo de núcleo que tiene todos los servicios del sistema operativo (como la gestión de memoria, el manejo de procesos y el sistema de archivos) en un único espacio de memoria. Los componentes del kernel monolítico trabajan juntos y están interrelacionados, lo que permite una comunicación rápida entre ellos, pero puede llevar a problemas de estabilidad si un componente falla.

**Ventajas:**
- Alta eficiencia y velocidad debido a la comunicación directa entre componentes.
- Capacidad de realizar operaciones complejas con bajo nivel de sobrecarga.

**Desventajas:**
- Mayor riesgo de errores y vulnerabilidades, ya que todo el código del kernel está en un solo espacio de memoria.
- Difícil de modificar y extender sin afectar al sistema completo.

**Ejemplos:**
- Linux
- UNIX

### 2. Kernel Microkernel

El microkernel es una arquitectura de kernel que minimiza la cantidad de código en modo núcleo, delegando la mayoría de las funcionalidades del sistema operativo a procesos en espacio de usuario. Esto significa que el núcleo sólo gestiona las operaciones básicas como la comunicación entre procesos y la gestión de interrupciones.

**Ventajas:**
- Mayor estabilidad y seguridad, ya que los servicios del sistema están separados y corren en espacio de usuario.
- Flexibilidad para agregar o modificar servicios sin afectar el núcleo.

**Desventajas:**
- Puede tener una menor eficiencia debido a la necesidad de comunicación entre el núcleo y los servicios en espacio de usuario.
- La complejidad en la comunicación entre procesos puede ser alta.

**Ejemplos:**
- Minix
- QNX

### 3. Kernel Híbrido

El kernel híbrido combina características de los kernels monolíticos y microkernels. Intenta ofrecer un equilibrio entre la eficiencia y la estabilidad al incluir algunos servicios en el núcleo y delegar otros a espacio de usuario.

**Ventajas:**
- Intento de combinar lo mejor de los dos enfoques (monolítico y microkernel).
- Ofrece un balance entre rendimiento y flexibilidad.

**Desventajas:**
- La complejidad del diseño puede ser alta.
- Puede no alcanzar el nivel óptimo de eficiencia o modularidad que los modelos puros.

**Ejemplos:**
- Windows NT
- macOS

## User Mode vs Kernel Mode

### User Mode

El User Mode es el modo de operación en el que las aplicaciones de usuario se ejecutan. En este modo, el código tiene acceso limitado al hardware y a las funcionalidades críticas del sistema. Cualquier operación que requiera acceso al hardware o que interfiera con el sistema operativo debe ser realizada a través de llamadas al sistema (system calls).

**Características:**
- Limitado en términos de acceso a los recursos del sistema.
- Menos riesgo de causar fallos críticos del sistema.
- Aislamiento entre aplicaciones para evitar que un fallo en una aplicación afecte al sistema completo.

### Kernel Mode

El Kernel Mode es el modo en el que el núcleo del sistema operativo y sus controladores funcionan. En este modo, el código tiene acceso completo al hardware y a todos los recursos del sistema. Las operaciones en Kernel Mode pueden realizar cualquier acción sin restricciones, incluyendo manipulación directa de hardware y memoria.

**Características:**
- Acceso completo a todos los recursos del sistema.
- Mayor riesgo de fallos del sistema, ya que los errores en el Kernel pueden llevar a inestabilidad del sistema completo.
- Operaciones de alto nivel y tareas críticas del sistema son gestionadas en este modo.

## Interrupciones vs Traps

### Interrupciones (Interrupts)

Las interrupciones son señales enviadas al procesador por hardware o software que indican que un evento necesita atención inmediata. Las interrupciones pueden ser generadas por eventos externos, como una señal de un dispositivo periférico, o por el propio sistema para manejar eventos temporales o urgentes.

**Características:**
- Permiten la respuesta rápida a eventos de hardware.
- Pueden ser gestionadas por el sistema operativo para atender eventos en tiempo real.
- Los procesadores pueden usar interrupciones para mejorar la eficiencia al delegar tareas a procesos de fondo.

### Traps

Los traps (o excepciones) son eventos generados por el procesador en respuesta a condiciones excepcionales durante la ejecución de instrucciones. Los traps pueden ser causados por errores como una división por cero, una instrucción inválida o una violación de acceso a memoria.

**Características:**
- Generan una interrupción al procesador para manejar condiciones de error.
- Los traps permiten al sistema operativo intervenir y gestionar errores o condiciones excepcionales de manera controlada.
- Son utilizados para realizar operaciones como el manejo de excepciones y la gestión de errores en el código.
