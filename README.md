# Algotopia

Algotopia is a fictional city that is built using the concepts and principles of Data 
Structures and Algorithms (DSA). The city is designed to showcase how DSA can be 
applied in real-world scenarios to solve various problems and challenges. It is built to 
demonstrate how DSA can be used to create efficient, scalable, and sustainable 
solutions to complex problems. It highlights the importance of understanding and 
applying these concepts in various fields such as computer science, engineering, 
finance, and healthcare.


## NEED STATEMENT:
The need statement that we have taken up is to design a new city that incorporates the best features of Matheran 
and Amsterdam.
Matheran is a small hill station that is famous for its natural beauty and pollution-free environment.
Amsterdam, on the other hand, is a city that is known for its canals and biking culture.
The goal of this project is to create a city that is not only visually appealing but also eco-friendly and has an 
efficient transportation system.
The focus is on incorporating biking and walking paths, water bodies, and green spaces, to make the city livable 
and sustainable. The city would be a blend of nature and urban living, aimed at creating a harmonious balance 
between the two.



## CITY NAME:

The name of the city is  ALGOTOPIA. <br>

It is a city inspired by Amsterdam and Matheran and made using the concepts of DSA.<br>

Algotopia is a fictional city that is built using the concepts and principles of Data Structures and Algorithms (DSA). 
The city is designed to showcase how DSA can be applied in real-world scenarios to solve various problems and challenges. 
It is built to demonstrate how DSA can be used to create efficient, scalable, and sustainable solutions to complex problems. 
It highlights the importance of understanding and applying these concepts in various fields such as computer science, engineering, 
finance, and healthcare.

<br>
Majorly the Data structures used for implementation are:
1.Array<br>
2.Stacks <br>
3.Queues <br>
4.Graphs <br>
5.BST <br>
6.AVL tree <br>
7.Hash tables <br>
8.Linked list <br>



## BRIEF IDEA:
--> Each node in the graph represents a specific location in the city. <br>
These locations might include residential areas, commercial areas, parks, water bodies, etc. <br>
LOCATION TYPES: <br>
0: Residential area <br>
1: Commercial area <br>
2: Park <br>
3: River/Lake <br>
4: Museum <br>
5: University/College <br>
6: Hospital <br>
7: Police station <br>
8: Fire station <br>
9: Train station <br>
10: Bus station <br>



### There are 2 weights on each edge in the graph.
One is the distance between the 2 places in kilometres. <br>
Second weight is the mode of transportation available between the 2 places. <br>
(1=walking, 2=cycling, 3=public transport, 4=car) <br>



## FUNCTIONALITIES IMPLEMENTED :


1.DFS/BFS to traverse the graph. <br>
DS used : Graphs <br>
Algorithm used : DFS <br>
Time complexity: O(V+E) , <br>
V: number of vertices <br>
E: number of edges. <br>



2.Dijkstra's can be used to find the shortest path from user given source to all other locations. <br>
<br>
DS used : Graphs <br>
Algorithm : Dijkstra's Algorithm using Arrays <br>
Time complexity: O(Elog(V)) <br>
V: number of vertices <br>
E: number of edges. <br>



3.Search for a location(see whether the user given location is there in city or not)-Linear Search<br>
<br>
Algorithm :Linear Search
<br>Time complexity: O(V)
<br>V:number of vertices


<br>
4.Create AVL tree and then apply inorder traversal for that.<br>
<br>
Concept used : AVL Tree.<br>
Then apply inorder traversal.<br>
Time complexity : O(log n)  <br>
for insertion and traversal. <br>


<br>
5.Find the shortest path b/w 2 locations.<br>
<br>
Algorithm : Floyd's Algorithm <br>
Finds the shorest path using user given 2 locations. <br>
Time complexity:O(n^3) <br>
n: number of nodes <br>



6.Find the locations that are completely eco friendly,based on sustainability rating.
Traverse and then find the locations having sustainability rating of 3.
Time complexity:O(V)
V:number of vertices/nodes <br>
<br>


7.Find the locations that are accessible by cycle/foot-based on accessible rating 
Traverse and then find the locations having accesibility rating of 1,2 <br>
<br>
1-by walk <br>
2.by cycle <br>
Time complexity:O(V) <br>
V:number of vertices/nodes <br>
<br>


8.Find the most connected location/central location.
Uses the adjacency matrix and finds the number of edges each node has.
Then displays the location which is having maximum connections. <br>
<br>
Time complexity:O(V^2) <br>
V:number of vertices/nodes <br>

<br>

9.Implementing efficient garbage collection and waste management. <br>
Algorithm: Kruskal's<br>
Uses MST algorithm like Kruskal to find the MST of the given graph
and thus finds out the distance to be travelled daily,to collect garbage from every location.<br>
Time complexity: O(Elog(V))<br>
V: number of vertices<br>
E: number of edges.<br>
<br>



10.Find the most populous city/
Finding the location with maximum population. <br>
Time complexity:O(V)<br>
V:number of vertices/nodes<br>
<br>


11.Find the minimum subset of roads that connect all buildings-Prims/Kruskal algorithm.<br>
Algorithm: Kruskal's<br>
Uses MST algorithm like Kruskal to find the MST of the given graph
Uses bubble sort to sort the edges.<br>
Time complexity: O(Elog(V))<br>
V: number of vertices<br>
E: number of edges.<br>
<br>


12.DFS to find the connected locations of the city<br>
Algorithm:DFS traversal for graphs<br>
Uses DFS and finds out the connected locations of the city.<br>
Time complexity:O(E)<br>
E:number of edges<br>
<br>


13.City with least population and completely eco-friendly.
Traverse the nodes and finds out the location,
which has the least population and also is completely eco friendly.<br>
Time complexity:O(V)<br>
V:number of vertices/nodes<br>
<br>



14.Find all the locations of particular type which is given by user.
Takes user input of location type,
and prints all the locations of that type.<br>
<br>
Time complexity:O(V)<br>
V:number of vertices/nodes<br>
<br>


15.Find all the locations that are accessible by a car. 
Traverses the graph and finds out the locations with accessibility rating of 3
and prints their names. <br>
<br>
Time complexity:O(V)<br>
V:number of vertices/nodes<br>
<br>


16.Allow user to see the entire city map.(print the graph)
Prints all the locations present in the city.
Then also prints edges of the city.<br>
<br>


17.Help user see the names of all locations present in city.
Prints the name of all locations.<br>
<br>
Time complexity:O(V)<br>
V:number of vertices/nodes<br>



18.print names of all police stations and fire station.
Prints names of all police stations and fire stations.<br>
<br>
Time complexity:O(V)<br>
V:number of vertices/nodes<br>
<br>


19.Hash the names of city and display the hash value.
Hashes the location names 
and then prints the hash value of the city along with the hash value.<br>
<br>
Time complexity: O(N*M), <br> 
where N is the number of nodes and 
M is the average length of a location name in characters. <br>

<br>

20.Display University with least population.<br>
Algorithm:Selection sort<br>
Time complexity:O(n^2)<br>
<br>


21.sort the cities according to population.(in decreasing order).<br>
Algorithm used : Quick sort<br>
Prints the cities in decreasing order of their population.<br>
Time complexity:O(n logn)<br>
<br>


22.Create a bst using the names of locations and find inorder traversal.<br>
Concept used : Binary Search tree(BST)<br>
Then applies preorder,postorder,inorder traversal.<br>
Time complexity:O(n) for traversals<br>
where n is number of nodes<br>

<br>

23.Detect whether any cycle is present in the city.<br>
Algorithm : DFS<br>
Uses DFS to find whether any cycle is present or not.
Also uses union to find if cycle is there.<br>
Time complexity:O(V+E)<br>
where V: number of vertices<br>
E:number of edges<br>
<br>


24.Sort the edges according to the distances.<br>
Algorithm : Insertion Sort<br>
Sorts the edges according to edge weight which is distance in this case.<br>
Time complexity:O(n^2)<br>
where n is number of vertices<br>
<br>


25.Use BFS to traverse the graph.<br>
Algorithm : BFS<br>
Performs BFS traversal on the graph.<br>
Time complexity:O(V+E)<br>
where V: number of vertices<br>
E:number of edges<br>



26.Find the transitive closure of graph by applying Warshall's algorithm.<br>
Algorithm : Warshall's Algorithm<br>
Finds the transitive closure of the graph,
and then prints the result to user.<br>
Time complexity:O(n^3)<br>
where n is number of vertices<br>



27.Sort the location names in lexicographical order<br>
Algorithm:Bubble sort<br>
Sorts the names of locations in alphabetical order.<br>
Time complexity:O(n^2)<br>




## CONTENTS OF nodes.txt

Ivy_Lane 0 5000 1 1<br>
Quiet_Valley 0 2000 2 2<br>
Louvre_Museum 4 2500 3 2<br>
Hilltop_View 0 5000 1 1<br>
Victoria_Coach_Station 10 30000 3 2<br>
Rose_Garden 2 4000 2 2<br>
City_Hall 1 5000 3 0<br>
Golden_Hills 0 4000 2 1<br>
Bright_Skyline 1 12000 4 1<br>
Diamond_Cove 0 7000 2 2<br>
Crystal_Creek 3 11000 2 2<br>
Starry_Night 1 9000 4 0<br>
Harvard_University 5 22000 3 2<br>
Lakeside_Retreat 3 10000 2 2<br>
Coastal_Bay 3 9000 1 1<br>
St.Mary's_Hospital 6 5000 2 3<br>
Oak_Hill 0 8000 1 1<br>
Sunny_Plaza 1 8000 4 0<br>
Main_Street 1 10000 4 0<br>
Mayo_Clinic 6 4000 3 3<br>
Central_Park 2 5000 3 2<br>
NewYork_Police_Department 7 500 1 3<br>
University_of_Toronto 5 88000 2 2<br>
Wild_Woods 0 3000 1 0<br>
Royal_Museum 4 6000 3 0<br>
Waterfront_View 3 8000 2 1<br>
Green_Meadow 2 8000 2 2<br>
London_King's_Cross_Station 9 70000 4 2<br>
Grand_Avenue 1 15000 4 3<br>
Bayfront_Park 2 10000 3 1<br>
British_Museum 4 2000 3 2<br>
Grand_Central_Station 9 100000 4 2<br>
Stella_River 3 12000 2 1<br>
Ocean_View 3 15000 1 1<br>
Forest_Trail 2 7000 2 2<br>
Blue_Harbor 3 12000 2 1<br>
Hillside_Lane 0 3000 1 2<br>
Pine_Forest 2 6000 3 1<br>
Civic_Center 1 7000 3 0<br>
Metropolitan_Police 7 150 1 2<br>
Maple_Grove 2 5000 3 1<br>
Port_Authority_Bus_Terminal 10 50000 3 2<br>
<br>
<br>


## Algorithms used:

1.Linear search<br>
2.Bubble sort<br>
3.Insertion sort<br>
4.Quick sort<br>
5.Floyd<br>
6.BFS<br>
7.DFS<br>
8.BFSS<br>
9.Selection sort<br>
10.Dijkstra's<br>
11.Warshall's Algorithm<br>


### Adjacency matrix
entry in the matrix is either 1 or 1.<br>
1 if edge exists bewteen u and v(u and v are the vertices) 
and 0 otherwise

