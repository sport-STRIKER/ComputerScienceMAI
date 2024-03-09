#include <gtest/gtest.h>
#include "include/declaration.h"
#include "include/npc.h"
#include "include/bear.h"
#include "include/squirrel.h"
#include "include/orc.h"
#include "include/factory.h"
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
    std::shared_ptr<Bear> bear1 = std::make_shared<Bear>(name, 1, 1);
    std::shared_ptr<Bear> bear2 = std::make_shared<Bear>(name, 1, 2);
    EXPECT_TRUE(bear1->accept(bear2) == false && bear2->accept(bear1) == false);
}

TEST(Test_Bear, FightSquirrel)
{
    std::string name = "asd";
    std::shared_ptr<Bear> bear = std::make_shared<Bear>(name, 1, 1);
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(name, 1, 2);
    EXPECT_TRUE(squirrel->accept(bear) == false);
}

TEST(Test_Bear, FightOrc)
{
    std::string name = "asd";
    std::shared_ptr<Bear> bear = std::make_shared<Bear>(name, 1, 1);
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(name, 1, 2);
    EXPECT_TRUE(orc->accept(bear) == false);
}

TEST(Test_Squirrel, Constr)
{
    std::string name = "asd";
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(name, 1, 2);
    EXPECT_TRUE(squirrel->getName() == name && squirrel->getType() == "SquirrelType");
}

TEST(Test_Squirrel, FightSquirrel)
{
    std::string name = "asd";
    std::shared_ptr<Squirrel> squirrel1 = std::make_shared<Squirrel>(name, 1, 1);
    std::shared_ptr<Squirrel> squirrel2 = std::make_shared<Squirrel>(name, 1, 2);
    EXPECT_TRUE(squirrel1->accept(squirrel2) == false && squirrel2->accept(squirrel1) == false);
}

TEST(Test_Squirrel, FightBear)
{
    std::string name = "asd";
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(name, 1, 1);
    std::shared_ptr<Bear> bear = std::make_shared<Bear>(name, 1, 2);
    EXPECT_TRUE(bear->accept(squirrel) == false);
}

TEST(Test_Squirrel, FightOrc)
{
    std::string name = "asd";
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(name, 1, 1);
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(name, 1, 2);
    EXPECT_TRUE(orc->accept(squirrel) == false);
}

TEST(Test_Orc, Constr)
{
    std::string name = "asd";
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(name, 1, 1);
    EXPECT_TRUE(orc->getName() == name && orc->getType() == "OrcType");
}

TEST(Test_Orc, FightOrc)
{
    std::string name = "asd";
    std::shared_ptr<Orc> orc1 = std::make_shared<Orc>(name, 1, 1);
    std::shared_ptr<Orc> orc2 = std::make_shared<Orc>(name, 1, 2);
    EXPECT_TRUE(orc1->accept(orc2) == true && orc2->accept(orc1) == true);
}

TEST(Test_Orc, FightBear)
{
    std::string name = "asd";
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(name, 1, 1);
    std::shared_ptr<Bear> bear = std::make_shared<Bear>(name, 1, 2);
    EXPECT_TRUE(bear->accept(orc) == true);
}

TEST(Test_Orc, FightSquirrel)
{
    std::string name = "asd";
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(name, 1, 1);
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(name, 1, 2);
    EXPECT_TRUE(squirrel->accept(orc) == false);
}

TEST(Test_NPC, Distance)
{
    std::string name = "asd";
    std::shared_ptr<Orc> orc1 = std::make_shared<Orc>(name, 1, 1);
    std::shared_ptr<Orc> orc2 = std::make_shared<Orc>(name, 4, 5);
    float distance = 5.0;
    EXPECT_TRUE(orc1->distance(orc2) == distance);
}

TEST(Test_NPC, Alive)
{
    std::string name = "asd";
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(name, 1, 1);
    EXPECT_TRUE(orc->isAlive() == true);
    orc->must_die();
    EXPECT_TRUE(orc->isAlive() == false);
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

TEST(Test_Factory, CreateNPC)
{
    std::string name = "asd";
    std::shared_ptr<NPC> obj = factory(NpcType(1), name, 1, 1);
    EXPECT_TRUE(obj->getName() == name && obj->getType() == "BearType");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}