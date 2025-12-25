#ifndef TYPES_H
#define TYPES_H

// Em vez de 'typedef char int8_t', usamos o cabeçalho padrão para evitar conflitos
#include <stdint.h>
#include <stddef.h>

// Definições extras que não existem no stdint.h
typedef uint32_t size_t;

#endif