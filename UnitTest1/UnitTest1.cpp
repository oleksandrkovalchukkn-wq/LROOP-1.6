#include "pch.h"
#include "CppUnitTest.h"
// Замість Project1 впиши назву папки свого основного проєкту:
#include "../LR1,6OOP/Long.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LongNestedUnitTests
{
    TEST_CLASS(LongNestedTests)
    {
    public:

        // Тест 1: Перевірка вкладеного класу Long::Pair::add
        TEST_METHOD(TestNestedPairAdd)
        {
            Long::Pair p1, p2;
            p1.Init(2, 600);
            p2.Init(1, 700);

            Long::Pair res = p1.add(p2);

            Assert::AreEqual(3, res.getFirst());
            Assert::AreEqual(1300, res.getSecond());
        }

        // Тест 2: Перевірка додавання Long::add із переносом розряду
        TEST_METHOD(TestLongAddWithCarry)
        {
            Long n1, n2;
            n1.Init(2, 600); // 2600
            n2.Init(1, 700); // 1700

            Long res = n1.add(n2); // 4300 -> старша 4, молодша 300

            Assert::AreEqual(4, res.getHigh());
            Assert::AreEqual(300, res.getLow());
        }

        // Тест 3: Перевірка віднімання та множення Long
        TEST_METHOD(TestLongSubAndMul)
        {
            Long n1, n2;
            n1.Init(3, 200); // 3200
            n2.Init(1, 500); // 1500

            Long diff = n1.sub(n2); // 1700
            Assert::AreEqual(1, diff.getHigh());
            Assert::AreEqual(700, diff.getLow());

            Long m1, m2;
            m1.Init(0, 50); // 50
            m2.Init(0, 30); // 30
            Long prod = m1.mul(m2); // 1500
            Assert::AreEqual(1, prod.getHigh());
            Assert::AreEqual(500, prod.getLow());
        }
    };
}