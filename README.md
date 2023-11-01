### Тестовое задание для компании CADEX

#### Запуск проекта

Для сборки проекта потребуется генератор проектных файлов CMake версии >= 3.16 и компилятор, поддерживающий C++17. 
Cборка производилась при помощи CMake 3.27 и компилятора clang версии 16.
1. Склонируйте репозиторий:

    ```git clone https://github.com/vglaznev/radex-test-task.git```
2. Войдите в папку с проектом:

    ```cd radex-test-task```
3. Cгенерируйте файлы сборки (при желании можете указать генератор через флаг -G):

    ```сmake -S. -Bbuild```
4. Cоберите проект:

    ```cmake --build build```
 
В директории `build` будут находится два артефакта сборки: `app` и `src`. В директории `app` находится исполняемый файл `cadex`, в директории `src` - динамичечкая библиотека `libcurves_library.so`.

Чтобы запустить программу:
    ```./build/app/cadex```

#### Пример вывода программы

```
Generated curves:
0 | Circle   | Radius   = 2.517 |                  |
1 | Ellipses | X radius = 2.742 | Y radius = 3.715 |
2 | Helix    | Radius   = 2.108 | Step     = 1.891 |
3 | Circle   | Radius   = 4.143 |                  |
4 | Helix    | Radius   = 1.558 | Step     = 4.104 |
5 | Circle   | Radius   = 3.139 |                  |
6 | Circle   | Radius   = 2.826 |                  |

Coordinates of points and derivatives at PI/4:
|         Point         |      Derivative       
0 | (1.779, 1.779, 0.000) | (-1.779, 1.779, 0.000) |
1 | (1.939, 2.627, 0.000) | (-1.939, 2.627, 0.000) |
2 | (1.490, 1.490, 1.485) | (-1.490, 1.490, 1.891) |
3 | (2.929, 2.929, 0.000) | (-2.929, 2.929, 0.000) |
4 | (1.102, 1.102, 3.223) | (-1.102, 1.102, 4.104) |
5 | (2.219, 2.219, 0.000) | (-2.219, 2.219, 0.000) |
6 | (1.999, 1.999, 0.000) | (-1.999, 1.999, 0.000) |

Circles:
0 | Circle  | Radius = 2.517 |
1 | Circle  | Radius = 4.143 |
2 | Circle  | Radius = 3.139 |
3 | Circle  | Radius = 2.826 |

Circles after sorting by radii:
0 | Circle  | Radius = 2.517 |
1 | Circle  | Radius = 2.826 |
2 | Circle  | Radius = 3.139 |
3 | Circle  | Radius = 4.143 |

Sum of radii in second container: 12.624
```