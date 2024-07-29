#!/bin/bash

# Leer la variable GITHUB_USER
read -p "Ingrese el nombre de usuario de github: " GITHUB_USER

if [ -z "$GITHUB_USER" ]; then
  echo "Error: La variable GITHUB_USER no está definida."
  exit 1
fi

# Consultar la URL
response=$(curl -s "https://api.github.com/users/$GITHUB_USER")

# Extraer la información necesaria
user_id=$(echo $response | jq -r '.id')
created_at=$(echo $response | jq -r '.created_at')

if [ "$user_id" == "null" ] || [ "$created_at" == "null" ]; then
  echo "No se pudo obtener información del usuario de GitHub."
  exit 1
fi

# Imprimir el mensaje
echo "Hola $GITHUB_USER, User ID: $user_id, Cuenta fue creada el $created_at"

# Crear el log file en /tmp/<fecha>/saludos.log
fecha=$(date '+%Y-%m-%d')
log_dir="/tmp/$fecha"
mkdir -p $log_dir
echo "Hola $GITHUB_USER, User ID: $user_id, Cuenta fue creada el $created_at" >> "$log_dir/saludos.log"