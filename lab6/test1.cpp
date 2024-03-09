#include <gtest/gtest.h>
#include "include/declaration.h"
#include "include/npc.h"
#include "include/bear.h"
#include "include/squirrel.h"
#include "include/orc.h"
#include "include/factory.h"
#include "include/fight.h"
#include "include/observerConsole.h"
#include "include/observerFile.h"

TEST(Test_Bear, Constr)
{
    std::string name = "asd";
    Bear bear{name, 1, 1};
    EXPECT_TRUE(bear.getName() == name && bear.getType() == "BearType");
}

TEST(Test_Bear, FightBear)
{
    std::string name = "asd";
    Bear bear1(name, 1, 1);
    Bear bear2(name, 1, 2);
    EXPECT_TRUE(bear1.accept(bear2) == false && bear2.accept(bear1) == false);
}

TEST(Test_Bear, FightSquirrel)
{
    std::string name = "asd";
    Bear bear{name, 1, 1};
    Squirrel squirrel{name, 1, 2};
    EXPECT_TRUE(squirrel.accept(bear) == true);
}

TEST(Test_Bear, FightOrc)
{
    std::string name = "asd";
    Bear bear{name, 1, 1};
    Orc orc{name, 1, 2};
    EXPECT_TRUE(orc.accept(bear) == false);
}

TEST(Test_Squirrel, Constr)
{
    std::string name = "asd";
    Squirrel squirrel{name, 1, 1};
    EXPECT_TRUE(squirrel.getName() == name && squirrel.getType() == "SquirrelType");
}

TEST(Test_Squirrel, FightSquirrel)
{
    std::string name = "asd";
    Squirrel squirrel1{name, 1, 1};
    Squirrel squirrel2{name, 1, 2};
    EXPECT_TRUE(squirrel1.accept(squirrel2) == false && squirrel2.accept(squirrel1) == false);
}

TEST(Test_Squirrel, FightBear)
{
    std::string name = "asd";
    Squirrel squirrel{name, 1, 1};
    Bear bear{name, 1, 2};
    EXPECT_TRUE(bear.accept(squirrel) == false);
}

TEST(Test_Squirrel, FightOrc)
{
    std::string name = "asd";
    Squirrel squirrel{name, 1, 1};
    Orc orc{name, 1, 2};
    EXPECT_TRUE(orc.accept(squirrel) == false);
}

TEST(Test_Orc, Constr)
{
    std::string name = "asd";
    Orc orc{name, 1, 1};
    EXPECT_TRUE(orc.getName() == name && orc.getType() == "OrcType");
}

TEST(Test_Orc, FightOrc)
{
    std::string name = "asd";
    Orc orc1{name, 1, 1};
    Orc orc2{name, 1, 2};
    EXPECT_TRUE(orc1.accept(orc2) == true && orc2.accept(orc1) == true);
}

TEST(Test_Orc, FightBear)
{
    std::string name = "asd";
    Orc orc{name, 1, 1};
    Bear bear{name, 1, 2};
    EXPECT_TRUE(bear.accept(orc) == true);
}

TEST(Test_Orc, FightSquirrel)
{
    std::string name = "asd";
    Orc orc{name, 1, 1};
    Squirrel squirrel{name, 1, 2};
    EXPECT_TRUE(squirrel.accept(orc) == false);
}

TEST(Test_NPC, Distance)
{
    std::string name = "asd";
    Orc orc1{name, 1, 1};
    Orc orc2{name, 4, 5};
    float distance = 5.0;
    EXPECT_TRUE(orc1.distance(orc2) == distance);
}

TEST(Test_NPC, InsertObservers)
{
    std::string name = "asd";
    Orc orc{name, 1, 1};
    ObserverConsole observer;
    orc.subscribe(std::make_shared<ObserverConsole>(observer));
    EXPECT_TRUE(orc.countObservers() == 1);
}

TEST(Test_NPC, EraseObservers)
{
    std::string name = "asd";
    Orc orc{name, 1, 1};
    ObserverFile observer;
    std::shared_ptr observer1 = std::make_shared<ObserverFile>(observer);
    orc.subscribe(observer1);
    orc.unsubscribe(observer1);
    EXPECT_TRUE(orc.countObservers() == 0);
}

TEST(Test_NPC, Print)
{
    std::string name = "asd";
    Orc orc{name, 1, 1};

    std::ostringstream coutstream;
    std::streambuf *coutbuf = std::cout.rdbuf(coutstream.rdbuf());

    std::cout << orc;

    std::cout.rdbuf(coutbuf);

    std::string s = "Type : OrcType, name : asd, x : 1, y : 1\n";

    EXPECT_TRUE(s == coutstream.str());
}

TEST(Test_NPC, Notify)
{
    std::string name = "asd";
    Bear bear{name, 1, 1};
    Squirrel squirrel{name, 1, 1};
    ObserverConsole observer;
    bear.subscribe(std::make_shared<ObserverConsole>(observer));
    squirrel.subscribe(std::make_shared<ObserverConsole>(observer));
    std::ostringstream coutstream;
    std::streambuf *coutbuf = std::cout.rdbuf(coutstream.rdbuf());

    squirrel.accept(bear);

    std::cout.rdbuf(coutbuf);

    std::string s = "BearType asd убил SquirrelType asd\n";
    std::cout << coutstream.str();
    EXPECT_TRUE(s == coutstream.str());
}

TEST(Test_Factory, CreateNPC)
{
    std::string name = "asd";
    std::shared_ptr<NPC> obj = factory(NpcType(1), name, 1, 1);
    EXPECT_TRUE(obj->getName() == name && obj->getType() == "BearType");
}

TEST(Test_Fight, FightBearWithOrc)
{
    std::string name = "asd";
    Bear bear{name, 1, 2};
    Orc orc{name, 1, 1};
    std::set<std::shared_ptr<NPC>> monsters {std::make_shared<Bear>(bear), 
                                             std::make_shared<Orc>(orc)};
    std::set<std::shared_ptr<NPC>> deadMonsters = fight(monsters, 10);
    EXPECT_TRUE(monsters != deadMonsters);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}