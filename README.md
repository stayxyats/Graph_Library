# Graph_Library
This is a simple Graph Library done in C++  
We have 6 classes, including exceptions handlings --- Despite old, this project follows the Hungarian Convention.  
  
CArc         -> handles the arc beetween the nodes
CSommet      -> handles everything related to the nodes, takes a pointer object to CArc. --- This is not yet a template, so specializing CArc can become sketchy, this is a work in progress.   
CGraphOrient -> handles the Oriented graph (arcs have a start and a end, they arent back & forth). This class is the mother of CGraph. This is a template taking <TArc, TSommet> therefore specialization is easy.  
CGraph       -> handles non-oriented graph, child of CGraphOrient, Arcs becomes edges (back&forth arcs). This is a template as well <TArc, TSommet>.  
CLecture     -> implements a graph from a *.txt documents. It has to follow a special convention, look into graph.txt to understand it  
  
(CException, handle most of the exception, there is probably more that can be added in)  
  
This project was coded outside of github, but there should be upcoming commits regarding a specialization of the CSommet class that would put colors on non-neighbors summits.
  
For more precision regarding the relations beetween classes, we have commited an astahUML class diagram.  
  
Its important to note that the commentary of the codes is done in French, as well as the functions names and the class diagram.  
