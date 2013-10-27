//"doublist.h"  
//Double circular linked list 

//class node
template <class type> class doublist;
template <class type> class node {
friend class doublist<type>;
private:
  node <type> * prior, * next;
  type data;
  node <type> ( ): prior (NULL), next (NULL) { }; 
     //constructor for header node
  node <type> ( type item, node <type> * prior0, node <type> * next0):
  data (item), prior (prior0), next (next0) { }; 
     //constructor for other nodes
  ~node ( ) { };
};

//class doublist
template <class type> class doublist{
private:
  node <type> * head, * pcurrent;
public:
  doublist ( );
  ~doublist ( );
  int Length ( ) const;                  //get length of dll
  type GetCurrent ( );                  //get the value of current dll
  int Locate (const type & x);     //locate the node which has data x
  void Insert ( const type & x );  //insert new node which has value x before current node
  void DeleteCurrent ( );              //delele current node 
  int  IsEmpty ( );                      
  void Clear (void);                   
  void Head ( ) {pcurrent = head;}     //pcurrent(current pointer) points to header node
  node <type> * Next ( );     //pcurrent points to the next node of current node
  node <type> * Prior ( );      //pcurrent points to the prior node of current node
};