#ifndef MAP_H
#define MAP_H

#include <iostream>

using namespace std;

class Map
{
private:
    const string UNEXPLORED = "-"; // marker for unexplored spaces
    const string EXPLORED = "-";   // marker for explored spaces
    const string FLOOR = "-"; // marker for floor spaces
    const string TABLE1 = "① ";       // marker for table locations
    const string TABLE2 = "② "; 
    const string TABLE3 = "③ "; 
    const string TABLE4 = "④ "; 
    const string TABLE5 = "⑤ "; 
    const string CRITIC = "🧛"; // marker for critic locations
    const string NPC = "👽";        // marker for NPC locations
    const string PLAYER = "😄";      // marker for party position
    const string LUNCH_BREAK = "🍱";   // marker for lunch break
    const string KITCHEN = "🍽️";   // marker for the kitchen

    static const int num_rows_ = 12; // number of rows in map
    static const int num_cols_ = 12; // number of columns in map
    static const int max_npcs_ = 5;  // max non-player characters
    static const int max_critic_ = 1;
    static const int max_tables_ = 5; // max number of rooms

    int player_position_[2];              // player position (row,col)
    int npc_positions_[max_npcs_][3];     // stores the (row,col) positions of NPCs present on map and if they have been found
    int table_positions_[max_tables_][2];   // stores the (row,col) positions of rooms present on map
    int critic_positions_[max_critic_][3];     // stores the (row,col) positions of NPCs present on map and if they have been found
    string map_data_[num_rows_][num_cols_]; // stores the character that will be shown at a given (row,col)
    
    int critic_count_;
    int npc_count_;  
    int table_count_;

public:
    Map();

    void resetMap();

    // getters
    int getPlayerRow();
    int getPlayerCol();
    int getTableCount();
    int getNPCCount();
    int getNumRows();
    int getNumCols();
    bool isOnMap(int row, int col);
    bool isNPCLocation(int row, int col);
    bool isCriticLocation(int row, int col);
    bool isTableLocation(int row, int col);
    bool isExplored(int row, int col);
    bool isFreeSpace(int row, int col);

    // setters
    void setPlayerPosition(int row, int col);

    // other
    void displayMap();
    bool move(char);
    bool addNPC(int row, int col);
    bool addTable(int row, int col);
    bool addCritic(int row, int col);
    bool removeNPC(int row, int col);
    bool removeTable(int row, int col);
    bool removeCritic(int row, int col);
    void exploreSpace(int row, int col);
};

#endif