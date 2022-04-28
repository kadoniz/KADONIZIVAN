/**
* @file Shifr.h
* @author Кадомцев И.Д.
* @version 1.0
* @brief Описание класса Shifr
* @date 27.04.2022
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/// @brief Класс для шифрования и расшифрования шифра табличной маршрутной перестановки
class Shifr
{
private:
 /// @brief атрибут, хранящий ключ для шифрования или расшифрования
    int key;
public:
    /// @brief Запрещающий конструктор без параметров
    Shifr() = delete;
     /// @brief Конструктор для ключа
     /**@param целочисленное число ключ
     */
    Shifr(int a);
    /** @brief Метод , предназначенный для шифрования шифром табличной маршрутной перестановки
     *@param экземляр класса "Shifr", в котором установился ключ
     *@param std::wstring - строка, которую нужно зашифровать
     * @return зашифрованная строка типа "wstring"
     */
    wstring enshifr(Shifr key, wstring &data);
    /** @brief Метод , предназначенный для расшифрования шифра табличной маршрутной перестановки
     *@param экземляр класса "Shifr", в котором установился ключ
     *@param std::wstring - строка, которую нужно расшифровать
     * @return расшифрованная строка типа "wstring"
     */
    wstring decshifr (Shifr key, wstring &data);
};
