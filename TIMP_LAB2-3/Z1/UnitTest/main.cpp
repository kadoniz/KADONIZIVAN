#include <UnitTest++/UnitTest++.h>
#include "/home/student/tlab2/modAlphaCipher.h"
#include "/home/student/tlab2/modAlphaCipher.cpp"
#include "/home/student/tlab2/exception.h"


SUITE(kl_tst) 
{
    TEST(BOLSHIE_BUKV) {
        modAlphaCipher test(L"АААА");
        CHECK(true);
    }

    TEST(malehenkie_bukovki) {
        modAlphaCipher test(L"ойойой");
        CHECK(true);
    }

    TEST(littleBig) {
        modAlphaCipher test(L"МиКс");
        CHECK(true);
    }
    TEST(iscluch_mix_num) {
        CHECK_THROW(modAlphaCipher test(L"раз1два2"),exc);
    }
     TEST(iscluch_mix_probel) {
        CHECK_THROW(modAlphaCipher test(L"про бел"), exc);
    }
     TEST(iscluch_mix_special_simbol) {
        CHECK_THROW(modAlphaCipher test(L"у(._.)у"),exc);
    }
    TEST(iscluch_pustota) {
        CHECK_THROW(modAlphaCipher test(L""), exc);
    }
   

   
}

struct KeyAB_fixture { // Для тестов шифрования и расшифрования
    modAlphaCipher * pointer;
    KeyAB_fixture()
    {
        pointer = new modAlphaCipher(L"ХЕХ");
    }
    ~KeyAB_fixture()
    {
        delete pointer;
    }
};

SUITE(enshifr) 
{
    TEST_FIXTURE(KeyAB_fixture, BOLSHIE_BUKV ) {
        wstring open_text = L"ОПАНА";
        wstring result_correct = L"ДФХГЕ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, malehenkie_bukovki ) {
        wstring open_text = L"опана";
        wstring result_correct = L"ДФХГЕ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, littleBig ) {
        wstring open_text = L"ОпАнА";
        wstring result_correct = L"ДФХГЕ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, iscluch_pustota ) {
        wstring open_text = L"";
        CHECK_THROW(pointer->encrypt(open_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_num) {
        wstring open_text = L"8МИЛЯ";
        CHECK_THROW(pointer->encrypt(open_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_special_symbol) {
        wstring open_text = L"Ф*К";
        CHECK_THROW(pointer->encrypt(open_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_probel) {
        wstring open_text = L"БЕЛ ПРО";
        CHECK_THROW(pointer->encrypt(open_text),exc);
    }

}
SUITE(decshifr) 
{
    TEST_FIXTURE(KeyAB_fixture, BOLSHIE_BUKV) {
        wstring cipher_text = L"ДФХГЕ";
        wstring result_correct = L"ОПАНА";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture, malehenkie_bukovki) {
        wstring cipher_text = L"дфхге";
        wstring result_correct = L"ОПАНА";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture, littleBig) {
        wstring cipher_text = L"ДФХГЕ";
        wstring result_correct = L"ОПАНА";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }

    TEST_FIXTURE(KeyAB_fixture, iscluch_pustota) {
        wstring cipher_text = L"";
        CHECK_THROW(pointer->decrypt(cipher_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_num ) {
        wstring cipher_text = L"МИЛЯ";
        CHECK_THROW(pointer->decrypt(cipher_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_special_symbol) {
        wstring cipher_text = L"Ф*К";
        CHECK_THROW(pointer->decrypt(cipher_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_probel) {
        wstring cipher_text = L"БЕЛ ПРО";
        CHECK_THROW(pointer->decrypt(cipher_text),exc);
    }
}
int main()
{
    return UnitTest::RunAllTests();
}
