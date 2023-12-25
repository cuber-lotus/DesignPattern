/**
 * @brief
 * https://www.jianshu.com/p/718fe24c3a35
 * 枚举 vs. 投币模式
 */

namespace old {
typedef unsigned int Amount;

enum Unit { FEET = 1, YARD = 3 * FEET, MILE = 1760 * YARD };

struct Length {
    Length(const Amount& amount, const Unit unit)
        : amountOfBaseUnit(unit * amount) {
        if (unit != MILE && unit != YARD && unit != FEET) {
            throw "error";
        }
    }

    bool operator==(const Length& another) const {
        return amountOfBaseUnit == another.amountOfBaseUnit;
    }

private:
    Amount amountOfBaseUnit;
};
}  // namespace old

namespace Slug_Pattern {
typedef unsigned int Amount;

struct Unit {
    // 允许用户使用的 Unit 对象
    static Unit getMile() {
        return MILE_FACTOR;
    }
    static Unit getYard() {
        return YARD_FACTOR;
    }
    static Unit getFeet() {
        return FEET_FACTOR;
    }

    Amount toAmountInBaseUnit(const Amount& amount) const {
        return conversionFactor * amount;
    }

private:
    // 构造函数私有以避免用户实例化 Unit 对象
    // 和上面三个`static`函数对应
    // 这里非常灵活的运用了语言的性质
    Unit(unsigned int conversionFactor) : conversionFactor(conversionFactor) {
    }

private:
    enum {
        FEET_FACTOR = 1,
        YARD_FACTOR = 3 * FEET_FACTOR,
        MILE_FACTOR = 1760 * YARD_FACTOR
    };

private:
    unsigned int conversionFactor;
};

// 通过宏定义,提供和原来一样的 Unit 使用方式。
#define MILE Unit::getMile()
#define YARD Unit::getYard()
#define FEET Unit::getFeet()

struct Length {
    /// 这里太秒了
    Length(const Amount& amount, const Unit& unit)
        : amountOfBaseUnit(unit.toAmountInBaseUnit(amount)) {
    }
    // ...
private:
    Amount amountOfBaseUnit;
};

}  // namespace Slug_Pattern
