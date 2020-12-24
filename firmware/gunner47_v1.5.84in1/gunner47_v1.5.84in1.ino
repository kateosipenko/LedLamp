//
// =================== ВНИМАНИЕ !!! =========================
//  Все настройки делаются на закладке Constants.h
//  Почитайте там то, что на русском языке написано.
//  Либо ничего не трогайте, если собирали, как в оригинале.
//
//  решение проблем можно поискать тут под спойлерами:
//  https://community.alexgyver.ru/goto/post?id=33652
// ==========================================================

// Ссылка для менеджера плат:
// https://arduino.esp8266.com/stable/package_esp8266com_index.json

/*
  Скетч к проекту "Многофункциональный RGB светильник"
  Страница проекта (схемы, описания): https://alexgyver.ru/GyverLamp/
  Исходники авторской (старой) прошивки на GitHub: https://github.com/AlexGyver/GyverLamp/
  исходники новой версии: https://community.alexgyver.ru/goto/post?id=33652
  Нравится лампа? Поддержи автора! https://alexgyver.ru/support_alex/
  Автор идеи и первой реализации: AlexGyver, AlexGyver Technologies, 2019
  https://AlexGyver.ru/
*/

/*
  Версия 1.5.84 эффекта в 1
  - Добавлены эффекты Кипение, Притяжение, Капли на стекле, Дымовые шашки, Тихий океан, Nexus
  - Убраны эффекты Белый огонь, Цветной огонь, Бeлый вoдoпaд, Быстрый пульс, Пульсирующая кoмeтa (копии и похожие эффекты уже не интересны даже в режиме Цикл, и так эффектов многовато)
  - Убран запрет обновления прошивки "по воздуху", когда лампа работает в виде точки доступа без роутера (в режиме ESP_MODE = 0).
  - Исправления в эффектах ДНК (добавлено управление бегунком Масштаб), Мячики без границ, Вихри, Разноцветные вихри, Стая, Стая и хищник (сглаживание)

  Версия 1.5.83 эффекта в 1
  - Добавлен эффект Огонь 2020.
  - Возвращён эффект Пульсирующая комета.
  - Устранены проблемы "хищник умер", "время бегущей строкой дёргается".
  - Убрано затухание лампы в момент смены эффектов. Убрана предварительная очистка изображения предыдущего эффекта, где было возможно.
  - Добавлены "секретные команды" для установки Будильника Рассвет и Таймера выключения из приложения Blynk (вдруг кому очень надо).

  Версия 1.5.81 эффект в 1
  - Удалён эффект Белая комета.
  - Временно удалён эффект Пульсирующая комета.
  - Временно добавлен эффект Осциллятор.
  - Обновлена поддержка приложения Blynk для управления текстом бегущей строки и передачи "секретных команд".
  - Эффекты Дым лучше адаптированы для ламп с плохим рассеивателем.
  - Найдена и убрана причина того, что в режиме Цикл лампа полностью гасла между эффектами.
  
  Версия 1.5.82 эффекта в 1
  - Удалён эффект Салют.
  - Добавлены эффекты Жидкая лампа и эффект Попкорн.
  - Реализована возможность установки времени на лампе без подключения к интернету (через приложение для Андроид от @Koteyka - оно есть в архиве с прошивкой).
  - Добавлена поддержка секретных команд reset=wifi, reset=effects, esp_mode=.. (через приложение для Андроид от @Koteyka - оно есть в архиве с прошивкой).
  
  Версия 1.5.80 эффектов в 1
  - В эффекте Цвет добавлена возможность выбора насыщенности бегунком Скорость.
  - Добавлены эффекты Тени, Мотыльки, Лампа с мотыльками, ДНК, Змейки, Салют.
  - Добавлена поддержка приложения Blynk (для iOS и Android) для ламп, имеющих постоянный доступ в Интернет. Если включить, будет всё немного подтормаживать.
  
  Версия 1.5.74 эффекта в 1
  - Добавлен эффект Лавовая лампа.
  
  Версия 1.5.73 эффекта в 1
  - Добавлены эффекты Пикассо.
  - Добавлен эффект Прыгуны.
  
  Версия 1.5.69 эффектов в 1 proper
  - В эффекте Белый свет сделано более плавное изменение площади свечения бегунком Масштаб (может, и зря).
  - В эффекте Метаболз наконец-то исправлена проблема перезагрузки лампы при длительной работе.

  Версия 1.5.69 эффектов в 1
  - Добавлены эффекты Дым и Разноцветный дым.

  Версия 1.5.67 эффектов в 1
  - Добавлен отдельный режим Часы. Просто как обычный предпоследний эффект. "Скорость" регулирует местоположение цифр. Чем лучше рассеивание на лампе, тем бесполезнее этот режим.
    Минимальная необходимая для Часов высота матрицы 11 пикселей. И 7 пикселей по ширине должно быть видно на одной стороне лампы, иначе часть циферблата уползёт на бок.
  - Исправлены баги в эффектах Кометы, вызывающие перезагрузку лампы при отличающихся друг от друга высоте и ширине матрицы, и при матрице высотой менее 14 пикселей.

  Версия 1.5.66 эффектов в 1
  - Все сложные настройки в Constants.h убраны вниз, чтобы не отвлекали.
  - Добавлены эффекты Мячики без границ (Прыжки), Кодовый замок и Кубик Рубика. Скрыт эффект Белые мячики (можно выбрать белый цвет обычным).
  - Добавлена возможность установить автоматическое выключение лампы после нескольких часов непрерывной работы (на случай, если кто-то забыл её выключить). 
    В приложении время выключения будет отображаться неверно, пока не исправят в будущих версиях.

  Версия 1.5.64 эффекта в 1
  - Добавлен эффект Мерцание.
  - Эффект Смена цвета теперь работает медленнее. На масштабах >10 переключение цвета будет через выбранное количество секунд (1 секунда для Скорости = 255 / 2 секунды для Скорости = 254 и т.д.)
  - В эффекте Метаболз добавлена возможность выбора палитры бегунком Масштаб
  - Обновлены эффекты Метель и Звездопад на версию от @Palpalych.
  - Добавлена возможность включить "очередь показов" выбранных эффектов для режима Цикл (чтобы не было повторов слишком часто). Это нужно включать в Constants.h.
  - Добавлена возможность выключить функцию "продолжить демонстрацию последнего эффекта после обесточивания лампы". Это нужно делать в Constants.h.
  - Исправлена размерность переменной currentMode. Возможно, теперь максимальное количество эффектов может быть больше 127 штук. Но это не точно.
  
  Версия 1.5.63 эффекта в 1
  - Добавлены эффекты Тучка в банке, Гроза в банке, Осадки, Огонь 2012.
  - Добавлена регулировка оттенка у эффекта Огонь 2018.
  - В Constants.h добавлен параметр для поддержки более свежей версии приложения от @Koteyka.
  - Оптимизированы функции parsing.h
  - Исправлена функция XY(). Это был аналог getPixelNumber(), но почему-то криво написанный.

  Версия 1.5.60 эффектов в 1
  - Добавлен эффект Огонь 2018.
  - Добавлена регулировка Масштаба у эффектов 2 кометы, 3 кометы, Парящий огонь, Верховой огонь.
  - Возможно, исправлена совместимость прошивки с матрицами, где способ подключения светодиодов отличается от "змейки".

  Версия 1.5.59 эффектов в 1
  - Создан массив настроек всех эффектов по умолчанию. Настройки выбраны с небольшой яркостью для работы в режиме ночника (для себя делал). Можете поставить яркость побольше.
  - Добавлен сброс настроек всех эффектов на значения по умолчанию при поступлении запроса от приложения ("загрузить список эффектов из лампы"). Можно отключить это в Constants.h.
  - Добавлены эффекты Вихри пламени и Разноцветные вихри.
  - В эффекте Светлячки со шлейфом теперь можно выбрать им цвета бегунком Масштаб.

  Версия 1.5.57 эффектов в 1
  - Объединено использование многих переменных в разных эффектах для небольшой экономии памяти.
  - Эффект Цвет тоже вынесен наверх в эффекты с принудительной задержкой в 50 мс, чтобы не травмировать контроллер платы.
  - Добавлены эффекты Стая, Стая и хищник, Призмата, Волны.
  - Увеличен размер буфера для приёма настроек Избранного от приложения в лампу. Теперь максимальное количество эффектов где-то в районе 117.
    (но это уже предел для текущей реализации функций FavoritesManager.h. дальше придётся менять там типы переменных).
  
  Версия 1.5.53 эффекта в 1
  - Изменён способ отправки списка эффектов в лампу. Теперь он не ограничен размером буфера, а ограничен хз чем.
  - Список эффектов расширен до 53 штук.
  - Добавлены новые функции, поддерживаемые приложением от @Koteyka (рисование, бегущая строка).
  
  Версия 1.5: 
    этот же список с гиперссылками: https://community.alexgyver.ru/threads/wifi-lampa-budilnik-obsuzhdenie-proshivki-ot-gunner47.2418/post-30883
  - Исправлен баг в условии процедуры вызова эффектов (у двух эффектов регулятор скорость не работал)
  - Инвертирована регулировка Скорости у всех эффектов, где она работала задом наперёд
  - Из всех эффектов убраны обращения к их порядковым номерам. Теперь любой эффект можно устанавливать на любое место (кроме номеров с 7 по 15), а также делать копии эффектов
  - Переработано распределение флеш-памяти EepromManager.h Теперь можно добавлять новые эффекты и делать копии (копии - для демонстрации одного эффекта на разных настройках).
  - В библиотеке FastLED исправлены коэффициенты расчёта потребления тока
  - Эффект Огонь заменён на "Ламповый огонь", при максимальном Масштабе он же будет эффект Белый огонь
  - Эффект Белый огонь заменён на эффект Водопад, при максимальном Масштабе цвет воды будет белым
  - Внесены исправления эффектов Пейнтбол и Радуга диагональная от @Palpalych (выставляйте Пейнтболу Скорость побольше, чтобы выглядело хорошо)
  - К эффекту Цвет добавлен эффект Бассейн (при максимальной Скорости блики воды исчезают, работает эффект Цвет)
  - К эффекту Смена цвета добавлен эффект Пульс (при минимальном Масштабе будет работать эффект Смена цвета)
  - Внесены исправления эффектов Метель и Звездопад от @Rampart
  - У эффекта Матрица изменена цветовая палитра и алгоритм работы (Нестыдная Матрица)
  - Эффект Светлячки со шлейфом заменён на эффект Кометы (в коде оставлены старый эффект, а также дополнительный Кометы мини, но они не подключены)
  - С прошивкой в архиве поставляется 2 приложения. Стандартное может работать только с 26 эффектами. При увеличении количества эффектов будет работать только приложение от @Koteyka
  - В архив с прошивкой добавлен файл с инструкцией в формате книжки. Правда, там уже устарели все ссылки.
  - Добавлен обработчик команды "GBR" для изменения яркости всех эффектов сразу без сохранения в энергонезависимую память. Приложение должно поддерживать данную функцию.
  - Добавлен обработчик команды "LIST" для отправки в приложение количества и реестра установленных эффектов. Приложение должно поддерживать данную функцию.

  Версия 1.4:
  - Исправлен баг при смене режимов
  - Исправлены тормоза в режиме точки доступа
  --- 08.07.2019
  - Исправлены параметры и процесс подключения к WiFi сети (таймаут 7 секунд) и развёртываия WiFi точки доступа (параметры имени/пароля)
  - Добавлено "#define USE_NTP" - позволяет запретить обращаться в интернет
  - Добавлено "#define ESP_USE_BUTTON - позволяет собирать лампу без физической кнопки, иначе яркость эффектов самопроизвольно растёт до максимальной
  - Переработаны параметры IP адресов, STA_STATIC_IP теперь пустой по умолчанию - избавляет от путаницы с IP адресами из неправильных диапазонов
  - Добавлено "#define GENERAL_DEBUG" - выводит в Serial/Telnet некоторые отладочные сообщения
  - Добавлено "#define WIFIMAN_DEBUG (true)" - выводит в Serial/Telnet отладочные сообщения библиотеки WiFiManager
  - Добавлена таблица с тест кейсами
  - Форматирование кода, комментарии
  --- 11.07.2019
  - Исправлена ошибка невыключения матрицы после срабатывания будильника, если до будильника матрица была выключенной
  - Дополнена таблица с тест кейсами
  --- 14.07.2019
  - Исправлена ошибка выключения будильника, если перед его срабатыванием был активен эффект "матрица" (или другой эффект, где задействовано мало светодиодов)
  - Добавлено управление по воздуху:
  -- работает только в режиме WiFi клиента
  -- работает при подключенной кнопке (потому что режим прошивки активируется кнопкой)
  --- 16.07.2019
  - Исправлено регулярное подвисание матрицы на 1-2 секунды при отсутствии подключения к интернету (но при успешном подключении к WiFi)
  --- 28.07.2019
  - Доработано взаимодействие с android приложением (отправка состояния после каждой операции)
  --- 01.08.2019
  - Возврат к стандартной библиотеке GyverButton (изменениё из неё перенесено в button.ino
  - Добавлены 2 эффекта: Светлячки со шлейфом и Белый свет
  - При запросе обновления по воздуху (2 четверных касания к кнопке) лампа переключается в режим "Матрица" для визуального подтверждения готовности к прошивке
  - В android приложение добавлена функция сканирования сети и добавления ламп с помощью multicast пакетов, доработка прошивки под это
  --- 03.08.2019
  - Исправлены ошибки взаимодействия android приложения с лампой, в вывод команды CURR добавлено текущее время (или millis(), если время не синхронизировано)
  --- 10.08.2019
  - Добавлена точная настройка яркости, скорости и масштаба эффектов
  - Добавлено взаимодействие с android приложением по управлению будильниками
  --- 14.08.2019
  - Добавлена функция таймера отключения
  --- 26.08.2019
  - Добавлен режим автоматического переключения избранных эффектов
  - Реорганизован код, исправлены ошибки
  --- 28.08.2019
  - Добавлен вызов режима обновления модуля esp из android приложения
  --- 30.08.2019
  - Эффект "Светлячки со шлейфами" переименован в "Угасающие пиксели"
  - Добавлены 5 новых эффекта: "Радуга диагональная", "Метель", "Звездопад", "Светлячки со шлейфами" (новый) и "Блуждающий кубик"
  - Исправлены ошибки
  --- 04.09.2019
  - Большая часть определений (констант) перенесена в файл Constants.h
  - Большая оптимизация использования памяти
  - Исправлена ошибка невключения эффекта "Белый свет" приложением и кнопкой
  - Исправлена ошибка неправильного выбора интервала в режиме Избранное в android приложении
  --- 16.09.2019
  - Добавлено сохранение состояния (вкл/выкл) лампы в EEPROM память
  - Добавлен новый эффект белого света (с горизонтальной полосой)
  - Реорганизован код, исправлены ошибки
  --- 20.09.2019
  - Добавлена возможность сохранять состояние (вкл/выкл) режима "Избранное"; не сбрасывается выключением матрицы, не сбрасывается перезапуском модуля esp
  - Убрана очистка параметров WiFi при старте с зажатой кнопкой; регулируется директивой ESP_RESET_ON_START, которая определена как false по умолчанию
  --- 24.09.2019
  - Добавлены изменения из прошивка от Alex Gyver v1.5: бегущая строка с IP адресом лампы по пятикратному клику на кнопку
  --- 29.09.2019
  - Добавлена опция вывода отладочных сообщений по пртоколу telnet вместо serial для удалённой отладки
  - Исправлена ошибка регулировки яркости кнопкой
  --- 05.10.2019
  - Добавлено управление по протоколу MQTT
  - Исправлена ошибка выключения будильника кнопкой
  - Добавлена задержка в 1 секунду сразу после старта, в течение которой нужно нажать кнопку, чтобы очистить сохранённые параметры WiFi (если ESP_RESET_ON_START == true)
  --- 12.10.2019
  - Добавлена возможность сменить рабочий режим лампы (ESP_MODE) без необходимости перепрошивки; вызывается по семикратному клику по кнопке при включенной матрице; сохраняется в EEPROM
  - Изменён алгоритм работы будильника:
  -  * обновление его оттенка/яркости происходит 1 раз в 3 секунды вместо 1 раза в минуту
  -  * диоды разбиты на 6 групп, первой из которых назначается новый оттенок/яркость 1 раз в 3 секунды, вторая "отстаёт" на 1 шаг, третья - на 2 шага и т.д. (для большей плавности)
  - Добавлена визуальная сигнализация о некоторых важных действиях/состояниях лампы:
  -  * при запуске в режиме WiFi клиента и ещё не настроенных параметрах WiFi сети (когда их нужно ввести)                                                     - 1 вспышка жёлтым
  -  * если лампа стартовала в режиме WiFi клиента с ненастроенными параметрами WiFi сети, и они не были введены за отведённый таймаут (перед перезагрузкой)   - 1 вспышка красным
  -  * при переходе лампы в режим обновления по воздуху (OTA) по двум четырёхкратным кликам по кнопке или по кнопке OTA из android приложения                  - 2 вспышки жёлтым
  -  * если лампа была переведена в режим OTA, но не дождалась прошивки за отведённый таймаут (перед перезагрузкой)                                            - 2 вспышки красным
  -  * при переключении рабочего режима лампы WiFi точка доступа/WiFi клиент семикратным кликом по кнопке (перед перезагрузкой)                                - 3 вспышки красным
  -  * при запросе вывода времени бегущей строкой, если время не синхронизировано                                                                              - 4 вспышки красным
  - Уменьшен таймаут подключения к WiFi сети до 6 секунд; вызвано увеличившейся продолжительностью работы функции setup(), она в сумме должна быть меньше 8 секунд
  - Оптимизирован код
  --- 14.10.2019
  - Если при первом старте в режиме WiFi клиента запрашиваемые имя и пароль WiFi сети не введены за отведённый таймаут (5 минут), лампа перезагрузится в режиме точки доступа
  - Добавлен вывод времени бегущей строкой:
  -  * по запросу - шестикратному клику - текущее время белым цветом;
  -  * периодически - определяется константой PRINT_TIME в Constants.h - от раза в час (красным цветом) до раза в минуту (синим цветом) с яркостью текущего эффекта как при включенной, так и при выключенной матрице
  --- 19.10.2019
  - Добавлены "ночные часы" (от NIGHT_HOURS_START до NIGHT_HOURS_STOP включительно) и "дневные часы" (всё остальное время), для которых доступна регулировка яркости для вывода времени бегущей строкой - NIGHT_HOURS_BRIGHTNESS и DAY_HOURS_BRIGHTNESS
  --- 20.10.2019
  - Добавлена блокировка кнопки на лампе из android приложения; сохраняется в EEPROM память
  --- 24.10.2019
  - Добавлен вывод сигнала (HIGH/LOW - настраивается константой MOSFET_LEVEL) синхронно с включением матрицы на пин MOSFET транзистора (настраивается константой MOSFET_PIN)
  - Добавлен вывод сигнала (HIGH/LOW - настраивается константой ALARM_LEVEL) на пин будильника (настраивается константой ALARM_PIN); сигнал подаётся в течение одной минуты, начиная со времени, на которое заведён будильник
  --- 02.11.2019
  - Добавлен переход на летнее/зимнее время (изменены настройки часового пояса, см. Constants.h); добавлена библиотека Timezone
  - Добавлен эффект Белый огонь
  - Исправлена ошибка сброса сигнала на пине ALARM_PIN при отключении будильника вручную
  - Добавлена сигнализация (4 вспышки красным) при запросе вывода времени шестикратным кликом, если время не синхронизировано
  --- 04.11.2019
  - Исправлена ошибка невключения MOSFET'а матрицы при срабатывании "рассвета"
  - Исправлена ошибка невключения MOSFET'а матрицы при выводе времени и IP адреса
  --- 08.11.2019
  - Исправлены ошибки назначения статического IP адреса
  - Добавлен набросок WiFiManager Captive Portal для ввода пользовательских параметров и настроек
*/

// Ссылка для менеджера плат:
// https://arduino.esp8266.com/stable/package_esp8266com_index.json

#define FASTLED_USE_PROGMEM 1 // просим библиотеку FASTLED экономить память контроллера на свои палитры

#include "pgmspace.h"
#include "Constants.h"
#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include "CaptivePortalManager.h"
#include <WiFiUdp.h>
#include <EEPROM.h>
#include "Types.h"
#include "timerMinim.h"
#ifdef ESP_USE_BUTTON
#include <GyverButton.h>
#endif
#include "fonts.h"
#ifdef USE_NTP
#include <NTPClient.h>
//#endif
//#if defined(USE_NTP) || defined(USE_MANUAL_TIME_SETTING)
#include <Timezone.h>
#endif
#include <TimeLib.h>
#ifdef OTA
#include "OtaManager.h"
#endif
#if USE_MQTT
#include "MqttManager.h"
#endif
#include "TimerManager.h"
#include "FavoritesManager.h"
#include "EepromManager.h"

#include <RemoteMe.h>
#include <RemoteMeSocketConnector.h>

#ifdef USE_BLYNK
#include <BlynkSimpleEsp8266.h>
#endif


// --- ИНИЦИАЛИЗАЦИЯ ОБЪЕКТОВ ----------
CRGB leds[NUM_LEDS];
WiFiManager wifiManager;
WiFiServer wifiServer(ESP_HTTP_PORT);
WiFiUDP Udp;

#ifdef USE_NTP
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, 0, NTP_INTERVAL); // объект, запрашивающий время с ntp сервера; в нём смещение часового пояса не используется (перенесено в объект localTimeZone); здесь всегда должно быть время UTC
//#endif
//#if defined(USE_NTP) || defined(USE_MANUAL_TIME_SETTING)
  #ifdef SUMMER_WINTER_TIME
  TimeChangeRule summerTime = { SUMMER_TIMEZONE_NAME, SUMMER_WEEK_NUM, SUMMER_WEEKDAY, SUMMER_MONTH, SUMMER_HOUR, SUMMER_OFFSET };
  TimeChangeRule winterTime = { WINTER_TIMEZONE_NAME, WINTER_WEEK_NUM, WINTER_WEEKDAY, WINTER_MONTH, WINTER_HOUR, WINTER_OFFSET };
  Timezone localTimeZone(summerTime, winterTime);
  #else
  TimeChangeRule localTime = { LOCAL_TIMEZONE_NAME, LOCAL_WEEK_NUM, LOCAL_WEEKDAY, LOCAL_MONTH, LOCAL_HOUR, LOCAL_OFFSET };
  Timezone localTimeZone(localTime);
  #endif
#endif

timerMinim timeTimer(3000);
bool ntpServerAddressResolved = false;
bool timeSynched = false;
uint32_t lastTimePrinted = 0U;

#ifdef USE_MANUAL_TIME_SETTING
time_t manualTimeShift;
//bool manualTimeSynched = false;
#endif


#ifdef ESP_USE_BUTTON
GButton touch(BTN_PIN, LOW_PULL, NORM_OPEN); // для физической (не сенсорной) кнопки нужно поменять LOW_PULL на HIGH_PULL. ну и кнопку нужно ставить без резистора между находящимися рядом пинами D2 и GND
#endif

#ifdef OTA
OtaManager otaManager(&showWarning);
OtaPhase OtaManager::OtaFlag = OtaPhase::None;
#endif

#if USE_MQTT
AsyncMqttClient* mqttClient = NULL;
AsyncMqttClient* MqttManager::mqttClient = NULL;
char* MqttManager::mqttServer = NULL;
char* MqttManager::mqttUser = NULL;
char* MqttManager::mqttPassword = NULL;
char* MqttManager::clientId = NULL;
char* MqttManager::lampInputBuffer = NULL;
char* MqttManager::topicInput = NULL;
char* MqttManager::topicOutput = NULL;
bool MqttManager::needToPublish = false;
char MqttManager::mqttBuffer[] = {};
uint32_t MqttManager::mqttLastConnectingAttempt = 0;
SendCurrentDelegate MqttManager::sendCurrentDelegate = NULL;
#endif

// --- ИНИЦИАЛИЗАЦИЯ ПЕРЕМЕННЫХ -------
uint16_t localPort = ESP_UDP_PORT;
char packetBuffer[MAX_UDP_BUFFER_SIZE];                     // buffer to hold incoming packet
char inputBuffer[MAX_UDP_BUFFER_SIZE];
static const uint8_t maxDim = max(WIDTH, HEIGHT);

ModeType modes[MODE_AMOUNT];
AlarmType alarms[7];

static const uint8_t dawnOffsets[] PROGMEM = {5, 10, 15, 20, 25, 30, 40, 50, 60};   // опции для выпадающего списка параметра "время перед 'рассветом'" (будильник); синхронизировано с android приложением
uint8_t dawnMode;
bool dawnFlag = false;
uint32_t thisTime;
bool manualOff = false;

uint8_t currentMode = 0;
uint8_t currentModeRemote = 0;
uint8_t brightnessLevelRemote = 100;
bool loadingFlag = true;
bool ONflag = false;
bool OnFlagRemote = false;
uint32_t eepromTimeout;
bool settChanged = false;
bool buttonEnabled = true;

unsigned char matrixValue[8][29]; //это массив для эффекта Огонь

bool TimerManager::TimerRunning = false;
bool TimerManager::TimerHasFired = false;
uint8_t TimerManager::TimerOption = 1U;
uint64_t TimerManager::TimeToFire = 0ULL;

uint8_t FavoritesManager::FavoritesRunning = 0;
uint16_t FavoritesManager::Interval = DEFAULT_FAVORITES_INTERVAL;
uint16_t FavoritesManager::Dispersion = DEFAULT_FAVORITES_DISPERSION;
uint8_t FavoritesManager::UseSavedFavoritesRunning = 0;
uint8_t FavoritesManager::FavoriteModes[MODE_AMOUNT] = {0};
uint32_t FavoritesManager::nextModeAt = 0UL;

bool CaptivePortalManager::captivePortalCalled = false;

// --- REMOTE ME ORG ------------------

RemoteMe& remoteMe = RemoteMe::getInstance(TOKEN, DEVICE_ID);


//*************** CODE FOR COMFORTABLE VARIABLE SET *********************

inline void setGarlandMode(String s) {remoteMe.getVariables()->setText("garlandMode", s); }

inline void setGarlandBrightness(int32_t i) {remoteMe.getVariables()->setInteger("garlandBrightness", i); }

inline void setGarlandPower(boolean b) {remoteMe.getVariables()->setBoolean("garlandPower", b); }

//*************** IMPLEMENT FUNCTIONS BELOW *********************

void onGarlandPowerChange(boolean b) {
  if (OnFlagRemote == b) {
    return;
  }
  
  FastLED.clear();
  delay(2);
  FastLED.show();
  OnFlagRemote = b;
  ONflag = b;
  changePower();
}

void onGarlandBrightnessChange(int32_t i) {
  if (brightnessLevelRemote == i) {
    return;
  }

  brightnessLevelRemote = i;
  modes[currentMode].Brightness = i;
  FastLED.setBrightness(modes[currentMode].Brightness);

  #ifdef GENERAL_DEBUG
  LOG.printf_P(PSTR("Новое значение яркости: %d\n"), modes[currentMode].Brightness);
  #endif
}

void onGarlandModeChange(String s) {
  LOG.println("NEW MODE ");
  LOG.print(s);

  if (s.equalsIgnoreCase("update")) {
   #ifdef OTA

    LOG.println("CHECK ESP MODE");
    if (espMode == 0U) {
      espMode = 1U;
      EepromManager::SaveEspMode(&espMode);

      #ifdef GENERAL_DEBUG
      LOG.printf_P(PSTR("Рабочий режим лампы изменён и сохранён в энергонезависимую память\nНовый рабочий режим: ESP_MODE = %d, %s\nРестарт...\n"),
        espMode, espMode == 0U ? F("WiFi точка доступа") : F("WiFi клиент (подключение к роутеру)"));
      delay(1000);
      #endif

      showWarning(CRGB::Red, 3000U, 500U);                    // мигание красным цветом 3 секунды - смена рабочего режима лампы, перезагрузка
      ESP.restart();
    }
   
    LOG.println("REQUEST UPDATE 1");
    if (otaManager.RequestOtaUpdate())
    {
      LOG.println("UPDATE 1");
      ONflag = true;
      currentMode = EFF_MATRIX;                             // принудительное включение режима "Матрица" для индикации перехода в режим обновления по воздуху
      FastLED.clear();
      delay(1);
      changePower();
    } else {
      delay (2000);
      LOG.println("REQUEST UPDATE 2");
      if (otaManager.RequestOtaUpdate())
      {
        LOG.println("UPDATE 2");
        ONflag = true;
        currentMode = EFF_MATRIX;                             // принудительное включение режима "Матрица" для индикации перехода в режим обновления по воздуху
        FastLED.clear();
        delay(1);
        changePower();
      }
      LOG.println("UPDATE FAILED");
    }
    #endif
  } else if (s.equalsIgnoreCase("sparkles")) {
    currentMode = EFF_SPARKLES;  
  } else if (s.equalsIgnoreCase("fire")) {
    currentMode = EFF_FIRE;  
  } else if (s.equalsIgnoreCase("rainbow vertical")) {
    currentMode = EFF_RAINBOW_VER;  
  } else if (s.equalsIgnoreCase("rainbow horizontal")) {
    currentMode = EFF_RAINBOW_HOR;  
  } else if (s.equalsIgnoreCase("rainbow diagonal")) {
    currentMode = EFF_RAINBOW_DIAG;  
  } else if (s.equalsIgnoreCase("colors")) {
    currentMode = EFF_COLORS;  
  } else if (s.equalsIgnoreCase("madness")) {
    currentMode = EFF_MADNESS;  
  } else if (s.equalsIgnoreCase("clouds")) {
    currentMode = EFF_CLOUDS;  
  } else if (s.equalsIgnoreCase("lava")) {
    currentMode = EFF_LAVA;  
  } else if (s.equalsIgnoreCase("plasma")) {
    currentMode = EFF_PLASMA;  
  } else if (s.equalsIgnoreCase("rainbow")) {
    currentMode = EFF_RAINBOW;  
  } else if (s.equalsIgnoreCase("rainbow stripe")) {
    currentMode = EFF_RAINBOW_STRIPE;  
  } else if (s.equalsIgnoreCase("zebra")) {
    currentMode = EFF_ZEBRA;  
  } else if (s.equalsIgnoreCase("forest")) {
    currentMode = EFF_FOREST;  
  } else if (s.equalsIgnoreCase("ocean")) {
    currentMode = EFF_OCEAN;
  } else if (s.equalsIgnoreCase("color")) {
    currentMode = EFF_COLOR;
  } else if (s.equalsIgnoreCase("snow")) {
    currentMode = EFF_SNOW;
  } else if (s.equalsIgnoreCase("snow storm")) {
    currentMode = EFF_SNOWSTORM;
  } else if (s.equalsIgnoreCase("starfall")) {
    currentMode = EFF_STARFALL;
  } else if (s.equalsIgnoreCase("matrix")) {
    currentMode = EFF_MATRIX;
  } else if (s.equalsIgnoreCase("lighters")) {
    currentMode = EFF_LIGHTERS;
  } else if (s.equalsIgnoreCase("lighters traces")) {
    currentMode = EFF_LIGHTER_TRACES;
  } else if (s.equalsIgnoreCase("paintball")) {
    currentMode = EFF_PAINTBALL;
  } else if (s.equalsIgnoreCase("cube")) {
    currentMode = EFF_CUBE;
  } else if (s.equalsIgnoreCase("white color")) {
    currentMode = EFF_WHITE_COLOR;
  } else {
    currentMode = EFF_SPARKLES;
  }
  
  FastLED.setBrightness(modes[currentMode].Brightness);
  loadingFlag = true;
  settChanged = true;
  eepromTimeout = millis();
}

// method will be called when user message came

void onUserMessage(uint16_t senderDeviceId, uint16_t dataSize, uint8_t *data) {
}

// this method will be called when sync message came to arduino You have to fill  returnData and returnDataSize
// as example now it reponse  one byte with 1 as value

void onUserSyncMessage(uint16_t senderDeviceId, uint16_t dataSize, uint8_t* data, uint16_t &returnDataSize, uint8_t *&returnData) {
  returnDataSize = 1;
  returnData = (uint8_t*)malloc(returnDataSize);
  returnData[0]=1;
}

// --- REMOTE ME ORG ------------------

char* TextTicker;
int Painting = 0; CRGB DriwingColor = CRGB(255, 255, 255);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  ESP.wdtEnable(WDTO_8S);


  // ПИНЫ
  #ifdef MOSFET_PIN                                         // инициализация пина, управляющего MOSFET транзистором в состояние "выключен"
  pinMode(MOSFET_PIN, OUTPUT);
  #ifdef MOSFET_LEVEL
  digitalWrite(MOSFET_PIN, !MOSFET_LEVEL);
  #endif
  #endif

  #ifdef ALARM_PIN                                          // инициализация пина, управляющего будильником в состояние "выключен"
  pinMode(ALARM_PIN, OUTPUT);
  #ifdef ALARM_LEVEL
  digitalWrite(ALARM_PIN, !ALARM_LEVEL);
  #endif
  #endif


  // TELNET
  #if defined(GENERAL_DEBUG) && GENERAL_DEBUG_TELNET
  telnetServer.begin();
  for (uint8_t i = 0; i < 100; i++)                         // пауза 10 секунд в отладочном режиме, чтобы успеть подключиться по протоколу telnet до вывода первых сообщений
  {
    handleTelnetClient();
    delay(100);
    ESP.wdtFeed();
  }
  #endif


  // КНОПКА
  #if defined(ESP_USE_BUTTON)
  touch.setStepTimeout(BUTTON_STEP_TIMEOUT);
  touch.setClickTimeout(BUTTON_CLICK_TIMEOUT);
    #if ESP_RESET_ON_START
    delay(1000);                                            // ожидание инициализации модуля кнопки ttp223 (по спецификации 250мс)
    if (digitalRead(BTN_PIN))
    {
      wifiManager.resetSettings();                          // сброс сохранённых SSID и пароля при старте с зажатой кнопкой, если разрешено
      LOG.println(F("Настройки WiFiManager сброшены"));
    }
    buttonEnabled = true;                                   // при сбросе параметров WiFi сразу после старта с зажатой кнопкой, также разблокируется кнопка, если была заблокирована раньше
    EepromManager::SaveButtonEnabled(&buttonEnabled);
    ESP.wdtFeed();
    #endif
  #endif


  // ЛЕНТА/МАТРИЦА
 
  FastLED.addLeds<WS2811, D6, COLOR_ORDER>(leds, 0, HEIGHT); // D1 // 5
  FastLED.addLeds<WS2811, D3, COLOR_ORDER>(leds, HEIGHT, HEIGHT); // D2 //4
  FastLED.addLeds<WS2811, D5, COLOR_ORDER>(leds, 2 * HEIGHT, HEIGHT); // D3 // 0
  FastLED.addLeds<WS2811, D7, COLOR_ORDER>(leds, 3 * HEIGHT, HEIGHT); // D4 // 2
  FastLED.addLeds<WS2811, D1, COLOR_ORDER>(leds, 4 * HEIGHT, HEIGHT); // D5 // 14
  FastLED.addLeds<WS2811, D8, COLOR_ORDER>(leds, 5 * HEIGHT, HEIGHT); // D6 // 12
  FastLED.addLeds<WS2811, D2, COLOR_ORDER>(leds, 6 * HEIGHT, HEIGHT); // D7 // 13
  FastLED.addLeds<WS2811, D4, COLOR_ORDER>(leds, 7 * HEIGHT, HEIGHT); // D8 // 15
//  
  // FastLED.addLeds<WS2812B, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS)/*.setCorrection(TypicalLEDStrip)*/;
  //FastLED.addLeds<WS2812B, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(0xFFB0F0); // по предложению @kostyamat добавлена такая цветокоррекция "теперь можно получить практически чистый желтый цвет" и получилось плохо
  FastLED.setBrightness(BRIGHTNESS);
  if (CURRENT_LIMIT > 0)
  {
    FastLED.setMaxPowerInVoltsAndMilliamps(5, CURRENT_LIMIT);
  }
  FastLED.clear();
  FastLED.show();

#ifdef USE_SHUFFLE_FAVORITES // первоначальная очередь избранного до перемешивания
    for (uint8_t i = 0; i < MODE_AMOUNT; i++)
      shuffleFavoriteModes[i] = i;
#endif


  // EEPROM
  EepromManager::InitEepromSettings(                        // инициализация EEPROM; запись начального состояния настроек, если их там ещё нет; инициализация настроек лампы значениями из EEPROM
    modes, alarms, &espMode, &ONflag, &OnFlagRemote, &dawnMode, &currentMode, &currentModeRemote, &brightnessLevelRemote, &buttonEnabled,
    &(FavoritesManager::ReadFavoritesFromEeprom),
    &(FavoritesManager::SaveFavoritesToEeprom),
    &(restoreSettings)); // не придумал ничего лучше, чем делать восстановление настроек по умолчанию в обработчике инициализации EepromManager
  LOG.printf_P(PSTR("Рабочий режим лампы: ESP_MODE = %d\n"), espMode);


  // WI-FI
  wifiManager.setDebugOutput(WIFIMAN_DEBUG);                // вывод отладочных сообщений
  // wifiManager.setMinimumSignalQuality();                 // установка минимально приемлемого уровня сигнала WiFi сетей (8% по умолчанию)
  CaptivePortalManager *captivePortalManager = new CaptivePortalManager(&wifiManager);
  if (false)                                        // режим WiFi точки доступа
  {
    // wifiManager.setConfigPortalBlocking(false);

    if (sizeof(AP_STATIC_IP))
    {
      LOG.println(F("Используется статический IP адрес WiFi точки доступа"));
      wifiManager.setAPStaticIPConfig(                      // wifiManager.startConfigPortal использовать нельзя, т.к. он блокирует вычислительный процесс внутри себя, а затем перезагружает ESP, т.е. предназначен только для ввода SSID и пароля
        IPAddress(AP_STATIC_IP[0], AP_STATIC_IP[1], AP_STATIC_IP[2], AP_STATIC_IP[3]),      // IP адрес WiFi точки доступа
        IPAddress(AP_STATIC_IP[0], AP_STATIC_IP[1], AP_STATIC_IP[2], 1),                    // первый доступный IP адрес сети
        IPAddress(255, 255, 255, 0));                                                       // маска подсети
    }

    WiFi.softAP(AP_NAME, AP_PASS);

    LOG.println(F("Старт в режиме WiFi точки доступа"));
    LOG.print(F("IP адрес: "));
    LOG.println(WiFi.softAPIP());

    wifiServer.begin();
  }
  else                                                      // режим WiFi клиента (подключаемся к роутеру, если есть сохранённые SSID и пароль, иначе создаём WiFi точку доступа и запрашиваем их)
  {
    LOG.println(F("Старт в режиме WiFi клиента (подключение к роутеру)"));

    if (WiFi.SSID().length())
    {
      LOG.printf_P(PSTR("Подключение к WiFi сети: %s\n"), WiFi.SSID().c_str());

      if (sizeof(STA_STATIC_IP))                            // ВНИМАНИЕ: настраивать статический ip WiFi клиента можно только при уже сохранённых имени и пароле WiFi сети (иначе проявляется несовместимость библиотек WiFiManager и WiFi)
      {
        LOG.print(F("Сконфигурирован статический IP адрес: "));
        LOG.printf_P(PSTR("%u.%u.%u.%u\n"), STA_STATIC_IP[0], STA_STATIC_IP[1], STA_STATIC_IP[2], STA_STATIC_IP[3]);
        wifiManager.setSTAStaticIPConfig(
          IPAddress(STA_STATIC_IP[0], STA_STATIC_IP[1], STA_STATIC_IP[2], STA_STATIC_IP[3]),// статический IP адрес ESP в режиме WiFi клиента
          IPAddress(STA_STATIC_IP[0], STA_STATIC_IP[1], STA_STATIC_IP[2], 1),               // первый доступный IP адрес сети (справедливо для 99,99% случаев; для сетей меньше чем на 255 адресов нужно вынести в константы)
          IPAddress(255, 255, 255, 0));                                                     // маска подсети (справедливо для 99,99% случаев; для сетей меньше чем на 255 адресов нужно вынести в константы)
      }
    }
    else
    {
      LOG.println(F("WiFi сеть не определена, запуск WiFi точки доступа для настройки параметров подключения к WiFi сети..."));
      CaptivePortalManager::captivePortalCalled = true;
      wifiManager.setBreakAfterConfig(true);                // перезагрузка после ввода и сохранения имени и пароля WiFi сети
      showWarning(CRGB::Yellow, 1000U, 500U);               // мигание жёлтым цветом 0,5 секунды (1 раз) - нужно ввести параметры WiFi сети для подключения
    }

    wifiManager.setConnectTimeout(ESP_CONN_TIMEOUT);        // установка времени ожидания подключения к WiFi сети, затем старт WiFi точки доступа
    wifiManager.setConfigPortalTimeout(ESP_CONF_TIMEOUT);   // установка времени работы WiFi точки доступа, затем перезагрузка; отключить watchdog?
    wifiManager.autoConnect(AP_NAME, AP_PASS);              // пытаемся подключиться к сохранённой ранее WiFi сети; в случае ошибки, будет развёрнута WiFi точка доступа с указанными AP_NAME и паролем на время ESP_CONN_TIMEOUT секунд; http://AP_STATIC_IP:ESP_HTTP_PORT (обычно http://192.168.0.1:80) - страница для ввода SSID и пароля от WiFi сети роутера

    delete captivePortalManager;
    captivePortalManager = NULL;

    if (WiFi.status() != WL_CONNECTED)                      // подключение к WiFi не установлено
    {
      if (CaptivePortalManager::captivePortalCalled)        // была показана страница настройки WiFi ...
      {
        if (millis() < (ESP_CONN_TIMEOUT + ESP_CONF_TIMEOUT) * 1000U) // пользователь ввёл некорректное имя WiFi сети и/или пароль или запрошенная WiFi сеть недоступна
        {
          LOG.println(F("Не удалось подключиться к WiFi сети\nУбедитесь в корректности имени WiFi сети и пароля\nРестарт для запроса нового имени WiFi сети и пароля...\n"));
          wifiManager.resetSettings();
        }
        else                                                // пользователь не вводил имя WiFi сети и пароль
        {
          LOG.println(F("Время ожидания ввода SSID и пароля от WiFi сети или подключения к WiFi сети превышено\nЛампа будет перезагружена в режиме WiFi точки доступа!\n"));

          espMode = (espMode == 0U) ? 1U : 0U;
          EepromManager::SaveEspMode(&espMode);

          LOG.printf_P(PSTR("Рабочий режим лампы изменён и сохранён в энергонезависимую память\nНовый рабочий режим: ESP_MODE = %d, %s\nРестарт...\n"),
            espMode, espMode == 0U ? F("WiFi точка доступа") : F("WiFi клиент (подключение к роутеру)"));
        }
      }
      else                                                  // страница настройки WiFi не была показана, не удалось подключиться к ранее сохранённой WiFi сети (перенос в новую WiFi сеть)
      {
        LOG.println(F("Не удалось подключиться к WiFi сети\nВозможно, заданная WiFi сеть больше не доступна\nРестарт для запроса нового имени WiFi сети и пароля...\n"));
        wifiManager.resetSettings();
      }

      showWarning(CRGB::Red, 1000U, 500U);                  // мигание красным цветом 0,5 секунды (1 раз) - ожидание ввода SSID'а и пароля WiFi сети прекращено, перезагрузка
      ESP.restart();
    }

    if (CaptivePortalManager::captivePortalCalled &&        // первое подключение к WiFi сети после настройки параметров WiFi на странице настройки - нужна перезагрузка для применения статического IP
        sizeof(STA_STATIC_IP) &&
        WiFi.localIP() != IPAddress(STA_STATIC_IP[0], STA_STATIC_IP[1], STA_STATIC_IP[2], STA_STATIC_IP[3]))
    {
      LOG.println(F("Рестарт для применения заданного статического IP адреса..."));
      delay(100);
      ESP.restart();
    }

    LOG.print(F("IP адрес: "));
    LOG.println(WiFi.localIP());

    // -- REMOTE ME ORG --------
    LOG.println("INITIALIZING REMOTE");
    remoteMe.getVariables()->observeText("garlandMode" ,onGarlandModeChange);
    remoteMe.getVariables()->observeInteger("garlandBrightness" ,onGarlandBrightnessChange);
    remoteMe.getVariables()->observeBoolean("garlandPower" ,onGarlandPowerChange);

    remoteMe.setUserMessageListener(onUserMessage);
    remoteMe.setUserSyncMessageListener(onUserSyncMessage);
    remoteMe.setConnector(new RemoteMeSocketConnector());
    remoteMe.sendRegisterDeviceMessage(DEVICE_NAME);

    #ifdef USE_BLYNK
    Blynk.config(USE_BLYNK);
    #endif
  }
  ESP.wdtFeed();

  LOG.printf_P(PSTR("Порт UDP сервера: %u\n"), localPort);
  Udp.begin(localPort);


  // NTP
  #ifdef USE_NTP
  timeClient.begin();
  ESP.wdtFeed();
  #endif


  // MQTT
  #if (USE_MQTT)
  if (espMode == 1U)
  {
    mqttClient = new AsyncMqttClient();
    MqttManager::setupMqtt(mqttClient, inputBuffer, &sendCurrent);    // создание экземпляров объектов для работы с MQTT, их инициализация и подключение к MQTT брокеру
  }
  ESP.wdtFeed();
  #endif


  // ОСТАЛЬНОЕ
  memset(matrixValue, 0, sizeof(matrixValue)); //это массив для эффекта Огонь. странно, что его нужно залить нулями
  randomSeed(micros());
  changePower();
  loadingFlag = true;

  TextTicker = "датути";
}


void loop()
{
  remoteMe.loop();
  parseUDP();
  if (Painting == 0) {

  effectsTick();

  EepromManager::HandleEepromTick(&settChanged, &eepromTimeout, &ONflag, &OnFlagRemote,
    &currentMode, &currentMode, &brightnessLevelRemote, modes, &(FavoritesManager::SaveFavoritesToEeprom));

  //#ifdef USE_NTP
  #if defined(USE_NTP) || defined(USE_MANUAL_TIME_SETTING)
  timeTick();
  #endif

  #ifdef ESP_USE_BUTTON
  if (buttonEnabled)
  {
    buttonTick();
  }
  #endif

  #ifdef OTA
  otaManager.HandleOtaUpdate();                             // ожидание и обработка команды на обновление прошивки по воздуху
  #endif

  TimerManager::HandleTimer(&ONflag, &settChanged,          // обработка событий таймера отключения лампы
    &eepromTimeout, &changePower);

  if (FavoritesManager::HandleFavorites(                    // обработка режима избранных эффектов
      &ONflag,
      &currentMode,
      &loadingFlag
      //#ifdef USE_NTP
      #if defined(USE_NTP) || defined(USE_MANUAL_TIME_SETTING)
      , &dawnFlag
      #endif
      ))
  {
    #ifdef USE_BLYNK
    updateRemoteBlynkParams();
    #endif
    FastLED.setBrightness(modes[currentMode].Brightness);
    //FastLED.clear(); из-за этой странной строчки между эффектами лампа полностью тухла. зачем так делать?!
    //delay(1); и из-за этой ещё
  }

  #if USE_MQTT
  if (espMode == 1U && mqttClient && WiFi.isConnected() && !mqttClient->connected())
  {
    MqttManager::mqttConnect();                             // библиотека не умеет восстанавливать соединение в случае потери подключения к MQTT брокеру, нужно управлять этим явно
    MqttManager::needToPublish = true;
  }

  if (MqttManager::needToPublish)
  {
    if (strlen(inputBuffer) > 0)                            // проверка входящего MQTT сообщения; если оно не пустое - выполнение команды из него и формирование MQTT ответа
    {
      processInputBuffer(inputBuffer, MqttManager::mqttBuffer, true);
    }
    
    MqttManager::publishState();
  }
  #endif

  #ifdef USE_BLYNK
  if (espMode == 1U && WiFi.isConnected())
    Blynk.run();
  #endif

  #if defined(GENERAL_DEBUG) && GENERAL_DEBUG_TELNET
  handleTelnetClient();
  #endif
  }
  ESP.wdtFeed();                                            // пнуть собаку
}
