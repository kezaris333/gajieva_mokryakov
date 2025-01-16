#!/bin/bash

#установка значений по умолчанию
default_config_file=".install-config"
default_permissions="0644"
default_user=$(whoami)
default_group=$(id -gn "$default_user")
default_path="$HOME"

#обработка аргументов
while getopts "o:p:m:u:g:a" opt; do
    case $opt in
        o) config_file="$OPTARG" ;;
        p) default_path="$OPTARG" ;;
        m) default_permissions="$OPTARG" ;;
        u) default_user="$OPTARG" ;;
        g) default_group="$OPTARG" ;;
        a) auto_mode=1 ;;
        *) echo "Неверный аргумент." && exit 1 ;;
    esac
done
shift $((OPTIND - 1))

#проверка на наличие каталога
if [ "$#" -ne 1 ]; then
    echo "Использование: $0 [-o <файл>] [-p <путь>] [-m <права>] [-u <пользователь>] [-g <группа>] [-a] <каталог>"
    exit 1
fi

target_dir="$1"

#проверка существования каталога
if [ ! -d "$target_dir" ]; then
    echo "Каталог $target_dir не существует."
    exit 1
fi

#установка имени файла конфигурации
config_file="${config_file:-$default_config_file}"

#создание или очистка файла конфигурации
> "$config_file"

#обработка файлов в указанном каталоге
for file in "$target_dir"/*; do
    # Пропуск, если это не файл
    [ ! -e "$file" ] && continue

    echo "Обработка файла: $file"

    # Запрос информации у пользователя
    read -p "Введите конечный каталог [${default_path}]: " input_path
    read -p "Введите права доступа [${default_permissions}]: " input_permissions
    read -p "Введите имя пользователя [${default_user}]: " input_user
    read -p "Введите имя группы [${default_group}]: " input_group

    # Установка значений по умолчанию, если пользователь ничего не ввел
    final_path="${input_path:-$default_path}"
    final_permissions="${input_permissions:-$default_permissions}"
    final_user="${input_user:-$default_user}"
    final_group="${input_group:-$default_group}"

    # Если включен автоматический режим, используем значения по умолчанию
    if [ "$auto_mode" ]; then
        final_path="$default_path"
        final_permissions="$default_permissions"
        final_user="$default_user"
        final_group="$default_group"
    fi

    #запись в файл настроек
    echo "$file : $final_permissions : $final_user : $final_group" >> "$config_file"
done

echo "Конфигурация сохранена в $config_file."
