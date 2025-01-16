#!/bin/bash

#функция для создания жестких ссылок
create_hard_links() {
    for file in "$@"; do
        #проверка, существует ли файл
        if [ ! -f "$file" ]; then
            echo "Файл $file не существует."
            continue
        fi

        base_name="${file%.*}"
        ext="${file##*.}"
        link_suffix=1

        #поиск первого доступного расширения
        while [ $link_suffix -le 9 ]; do
            link_name="${base_name}.${link_suffix}"
            if [ ! -e "$link_name" ]; then
                ln "$file" "$link_name"
                echo "Создана жесткая ссылка: $link_name"
                break
            fi
            link_suffix=$((link_suffix + 1))
        done

        #если все расширения до .9 заняты
        if [ $link_suffix -gt 9 ]; then
            echo "Не удалось создать ссылку для $file: все расширения заняты."
        fi
    done
}

#функция для удаления жестких ссылок
remove_hard_links() {
    for file in "$@"; do
        # Проверка, существует ли файл
        if [ ! -f "$file" ]; then
            echo "Файл $file не существует."
            continue
        fi

        base_name="${file%.*}"

        for link_suffix in {1..9}; do
            link_name="${base_name}.${link_suffix}"
            if [ -e "$link_name" ]; then
                rm "$link_name"
                echo "удалена жесткая ссылка: $link_name"
            fi
        done
    done
}

#обработка аргументов
if [ "$#" -eq 0 ]; then
    echo "Использование: $0 [-r] <файлы...>"
    exit 1
fi

if [ "$1" == "-r" ]; then
    shift # Убираем флаг -r
    remove_hard_links "$@"
else
    create_hard_links "$@"
fi
