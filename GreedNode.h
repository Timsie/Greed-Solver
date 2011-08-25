#include <iostream>
#include <cstdlib>

#typedef unsigned short int greedMatrix[22][80];
class GreedNode
{
    enum Direction
    {
        ABOVE,
        BELOW,
        LEFT,
        RIGHT
    };

    struct Location
    {
        unsigned short int x;
        unsigned short int y;
    };
    
    public:
        GreedNode(unsigned short int id, Greednode* parent, Direction dir);

        ~GreedNode();

        greedMatrix getClearedMatrix();

        unsigned short int getId();

        unsigned short int getParentId();

        Location getLocation();
        
        Direction getDirectionCameFrom();

        void setLocation(Location loc);

        void setParentId(unsigned short int pId);

        void setId(unsigned short int id);
        
        void setDirectionCameFrom(Direction dir);

    private:

        void setClearedMatrix(greedMatrix parentMatrix);

        greedMatrix m_clearedMatrix;
        
        Direction m_dirCameFrom;

        Location m_location;

        unsigned short int m_id;
        
        unsigned short int m_parentId;

        bool m_lastNode;
};
