# InteractionSystem

## Assembly instructions

- Unreal Engine version 5.1 or higher. 
- For the functionality to work, after starting the UE editor in the multiplayer settings, select in `Net Mode` select `Play As Client`
- Works with any number of players.

## Tasks solved in the project

**Task №1**

When the project is launched, a widget is activated that requests a name, which is then displayed above the player's head in 3D space.
Works with local multiplayer, the number of players is not limited.

**Task №2**

The level has a "Lever" object that remotely activates (opens/closes) the "Door" object.
Any player within local multiplayer can interact with the lever.

**Additional details for solving **Task №2:**

- You can customize what the character can interact with
- The lever can interact with any number of doors
- The door changes state when interacting with the lever






## Инструкция по сборке. 

- Версия Unreal Engine 5.1 или выше. 
- Для работы функционала, после запуска редактора UE в настройках мультиплеера выбрать в `NetMode` выбрать `Play As Client`
- Работает при любом количестве игроков. 

## Задачи решенные в проекте

**Задача №1**

При запуске проекта активируется виджет который, запрашивает имя которое, потом отображается над головой игрока в 3Д пространстве.
Работает при локальном мультиплеере, количество игроков не ограничено. 

**Задача №2**

На уровне есть объект "Рычаг" который удаленно приводить в действие (открывает/закрывает) объект "Дверь".
Любой игрок в рамках локального мультиплеера может взаимодействоватьс рычагом. 

**Дополнительные детали решения Задачи №2:**

- Можно настраивать с чем может взаимодейстовать персонаж 
- Рычаг может взаимодействовать с любым количеством дверей
- Дверь меняет состояние при взаимодействии с рычагом 
