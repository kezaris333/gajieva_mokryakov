#!/bin/bash

#фнкция для вывода инструкции
print_help() {
    echo "Использование: $0 [-d каталог] [-e файл_ошибок] имя_файла"
    echo "  -d каталог      Путь к начальному каталогу (по умолчанию текущий)"
    echo "  -e файл_ошибок Перенаправление сообщений об ошибках в указанный файл"
    echo "  -h              Печать этой инструкции и выход"
    exit 0
}

#обработка аргументов
while getopts ":d:e:h" opt; do
    case ${opt} in
        d )
            directory="$OPTARG"
            ;;
        e )
            error_file="$OPTARG"
            exec 2>>"$error_file"
            ;;
        h )
            print_help
            ;;
        \? )
            echo "Неверный флаг: $OPTARG" >&2
            exit 1
            ;;
        : )
            echo "Неверный флаг: $OPTARG требует аргумент." >&2
            exit 1
            ;;
    esac
done
shift $((OPTIND -1))

# Проверка на наличие имени файла
if [ $# -ne 1 ]; then
    echo "Необходимо указать имя файла." >&2
    exit 1
fi

file_name="$1"

#установка каталога по умолчанию, если не указан
if [ -z "$directory" ]; then
    directory="."
fi

#поиск файла
find "$directory" -type f -name "$file_name" 2>>"$error_file"
