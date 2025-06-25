
#include <iostream>
#include "UserInterface.hpp"

///@defgroup Business-Core Business Core
///@brief Основные инструменты управления и взаимодействия

///@defgroup Staff Staff
///@brief Базовые классы персонала

///@defgroup Theme Theme
///@brief Инструменты управления цветовыми схемами

///@defgroup Provider Providers
///@brief Инструменты взаимодействия с файлами

///@defgroup Repository Repository
///@brief Инструменты хранения и управления персоналом

///@defgroup Utils Utils
///@brief Вспомогательные утилиты

///@defgroup UI-Core User Interface Core
///@brief Главные механизмы GUI/TUI

///@defgroup Model Models
///@brief Модели, инкапсулирующие взаимодействие с бизнес-логикой

///@defgroup ViewModel ViewModels
///@brief Модели представления UI

///@defgroup View Views
///@brief Представления UI




int main() {
    core::UserInterface UI;
    UI.run();
    system("pause");
    return 0;
}
