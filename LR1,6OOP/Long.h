#pragma once
#include <string>

class Long {
public:
    // Вкладений клас Pair
    class Pair {
    private:
        int first;
        int second;

    public:
        int getFirst() const { return first; }
        int getSecond() const { return second; }

        bool setFirst(int value);
        bool setSecond(int value);

        bool Init(int a, int b);
        void Read();
        void Display() const;
        std::string toString() const;

        // Додавання пар за формулою: (a, b) + (c, d) = (a + c, b + d)
        Pair add(const Pair& other) const;
    };

private:
    static const int BASE = 1000; // База молодшого розряду (0..999)
    Pair pair;                    // Поле вкладеного класу

    long long toValue() const;
    void fromValue(long long val);

public:
    Long::Pair getPair() const { return pair; }
    int getHigh() const { return pair.getFirst(); }
    int getLow() const { return pair.getSecond(); }

    bool setPair(Long::Pair p);
    bool setHigh(int high);
    bool setLow(int low);

    bool Init(int high, int low);
    bool Init(Long::Pair p);
    void Read();
    void Display() const;
    std::string toString() const;

    // Операції класу Long (Варіант 18)
    Long add(const Long& other) const;
    Long sub(const Long& other) const;
    Long mul(const Long& other) const;
};