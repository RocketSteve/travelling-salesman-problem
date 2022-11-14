int main(){
    string filename = "random.txt";

    //randomInstanceGenerator(4, 10);

    coordSystem test(filename);


    adjMatrix graph(test.V);
    adjMatrix graphCopy(test.V);

    test.convert(graph);
    test.convert(graphCopy);

    auto start = high_resolution_clock::now();

    adjMatrix ans = graph.travellingSalesman_start(0, graphCopy);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << duration.count() << "µs - czas wykonania algorytmu zachłannego\n";

    graph.printAns();

    return 0;
}