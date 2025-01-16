#Определите кол-во всех строк, находящихся в в файлах, которые переданы в виде параметров скрипа/функции

#!/bin/bash

if [ "$#" -eq 0 ]; then
echo "Пожалуйста, укажите хотя бы один файл"
    exit 1
fi

total_lines=0
    for file in "$@"; do
#проверяем существует ли файл
        if [-f "file"]; then
#считаем строки в файле и добавляем к общему кол-ву
            lines_in_file=$(wc-1 < "$file")
            #wc-1 возвращает количество строк
            total_lines=$((total_kines + lines_in_file))
        else
            echo "Файл '$file' не найден."
            
            fi
            done
            
            echo "общее количество строк $total_lines"
