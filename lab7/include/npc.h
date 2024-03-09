#pragma once

#include "declaration.h"
#include "observer.h"

class NPC : public std::enable_shared_from_this<NPC>
{
    public:
        NPC(NpcType _type, std::string _name, int _x, int _y);
        NPC(NpcType _type, std::istream& is);
        virtual ~NPC() = default;

        std::string getName();
        std::string getType();
        int getIntType();
        virtual int getDistMove() = 0;
        virtual int getDistFight() = 0;
        bool isAlive();
        void must_die();
        bool isClose(const std::shared_ptr<NPC> &other);
        std::pair <int, int> position();
        float distance(const std::shared_ptr<NPC> &other);
        void move(int shift_x, int shift_y, int max_x, int max_y);
        bool win();

        virtual bool accept(std::shared_ptr<NPC> visitor) = 0;
        virtual bool visit(std::shared_ptr<Bear> monster);
        virtual bool visit(std::shared_ptr<Squirrel> monster);
        virtual bool visit(std::shared_ptr<Orc> monster);

        size_t countObservers() const;
        void subscribe(std::shared_ptr<Observer> observer);
        void unsubscribe(std::shared_ptr<Observer> observer);
        void notify(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> defender) const;

        friend std::ostream &operator<<(std::ostream &os, NPC &npc);

    protected:
        std::mutex mtx;

        NpcType type;
        std::string name;
        int x;
        int y;
        int dist_move;
        int dist_fight;
        bool alive;
        std::set<std::shared_ptr<Observer>> observers;
};
