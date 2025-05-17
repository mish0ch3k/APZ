# Практична 1 (pr1)

## Опис
Цей скрипт на Bash шукає бібліотеки у `/usr/lib` і перевіряє, чи є в них функції `sin`, `cos` та `exp`. Він перебирає всі `.so` файли та перевіряє їх за допомогою `nm -D`.

## Як запустити
1. Клонуйте репозиторій:
   ```bash
   git clone https://github.com/mish0ch3k/APZ
   ```
2. Дайте файлу права на виконання:
   ```bash
   chmod +x find_functions.sh
   ```
3. Запустіть у терміналі:
   ```bash
   ./find_functions.sh
   ```

## Як це працює
- `LIB_DIR` – це папка, де шукаємо бібліотеки (за замовчуванням `/usr/lib`).
- `FUNCTIONS` – список функцій, які шукаємо (`sin`, `cos`, `exp`).
- Скрипт шукає всі `.so` файли в папці `LIB_DIR`.
- За допомогою `nm -D` перевіряє, чи є в них потрібні функції.
- Якщо знайдено, виводить щось типу:
  ```
  Lib /usr/lib/libm.so have func sin
  ```

## Вимоги
- Linux або WSL (Windows Subsystem for Linux)
- Утиліта `nm` (з пакету `binutils`)

## Як змінити цільову директорію для перевірки
Якщо потрібно перевіряти іншу папку, змініть `LIB_DIR`, наприклад:
```bash
LIB_DIR="/lib/x86_64-linux-gnu"
```


# Практична 2 (pr2)

## Опис

Ця практична містить приклади програм і дослідження архітектури виконуваних файлів, памʼяті процесу (stack, heap, data, bss, text), функції `mmap()` проти `malloc()`, і аналізу стеку за допомогою `gstack` та `gdb`.

## Як запустити

```bash
git clone https://github.com/mish0ch3k/APZ
cd APZ
gcc p21.c -o time_check
./time_check

gcc p23.c -o segments
./segments

gcc mmap.c -o test_mmap
./test_mmap
```
Файл p24 потрібно запускати окремо, потім відкрити інший термінал і виконати:
```bash
gcc p24.c -o trace
./trace    
gstack <PID>       # або
gdb -p <PID> -> bt
```

## Аналіз mmap vs malloc
malloc.c — виділяє 10 МБ памʼяті через heap.

mmap.c — виділяє ті ж 10 МБ, але напряму через mmap.

За допомогою pmap <PID> можна побачити різницю:

malloc → heap

mmap → окремий регіон памʼяті

## Вимоги
Linux або WSL
GCC
gdb, gstack або pstack
binutils (для nm, size, objdump)