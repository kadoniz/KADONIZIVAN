/**
* @file exception.h
* @author Кадомцев И.Д.
* @version 1.0
* @brief Описание класса exc
* @date 27.04.2022
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <stdexcept>
#include <string>
using namespace std;
/// @brief  Класс для обработки ошибок, которые могут возникнуть при взаимодействии с программой
/// @details Класс наследует существующий класс обработки исключений с именем "invalid_argument" из библиотеки "stdexcept".
class exc : public invalid_argument
{
public:
  exc(const string & error) : invalid_argument(error){};
   
};
