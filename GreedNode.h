#include <iostream>
#include <cstdlib>

typedef unsigned short int greedMatrix[22][80];

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
        GreedNode(unsigned short int id, GreedNode* parent,
                  unsigned short int numMoved, Direction dir);

        ~GreedNode();

        greedMatrix& getClearedMatrix();

        unsigned short int getId();

        GreedNode* getParent();

        Location getLocation();
        
        Direction getDirectionCameFrom();

        void setLocation(Location loc);

        void setParent(GreedNode& parent);

        void setId(unsigned short int id);
        
        void setDirectionCameFrom(Direction dir);

    private:

        void setClearedMatrix(greedMatrix& parentMatrix);

        greedMatrix* m_clearedMatrix;

        unsigned short int m_id;
        
        unsigned short int m_numberOfMoves;

        GreedNode* m_parent;
        
        Direction m_dirCameFrom;

        Location m_location;

        bool m_lastNode;
};
