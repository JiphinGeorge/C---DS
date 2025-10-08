import networkx as nx
import matplotlib.pyplot as plt
import heapq
import time

def draw_step(graph, pos, mst_edges, visited, current_edge, explanation):
    plt.clf()  # Clear previous plot

    # Draw the base graph
    nx.draw(graph, pos, with_labels=True, node_color='lightgray', edge_color='gray')

    # Highlight visited nodes
    nx.draw_networkx_nodes(graph, pos, nodelist=visited, node_color='lightgreen')

    # Highlight MST edges
    nx.draw_networkx_edges(graph, pos, edgelist=mst_edges, edge_color='red', width=2)

    # Highlight current edge being considered
    if current_edge:
        nx.draw_networkx_edges(graph, pos, edgelist=[current_edge], edge_color='blue', width=2, style='dashed')

    # Draw edge weights
    edge_labels = nx.get_edge_attributes(graph, 'weight')
    nx.draw_networkx_edge_labels(graph, pos, edge_labels=edge_labels)

    # Display the explanation text
    plt.title("Prim's Algorithm Step-by-Step")
    plt.text(0, -1.1, explanation, fontsize=10, ha='center', wrap=True)

    plt.pause(2)  # Pause to simulate animation

def prim_animated(graph, start):
    visited = set()
    min_heap = [(0, start, None)]  # (weight, node, parent)
    mst_edges = []
    pos = nx.spring_layout(graph, seed=42)  # Consistent layout

    plt.ion()
    plt.figure(figsize=(8, 6))

    step = 1
    while min_heap:
        weight, u, parent = heapq.heappop(min_heap)

        if u in visited:
            continue

        explanation = f"Step {step}: Visit node '{u}'"
        if parent:
            mst_edges.append((parent, u))
            explanation += f" from '{parent}' via edge ({parent}, {u}) with weight {weight}."
        else:
            explanation += " (starting node)."
        step += 1

        visited.add(u)
        draw_step(graph, pos, mst_edges, visited, (parent, u) if parent else None, explanation)

        for v in graph[u]:
            if v not in visited:
                heapq.heappush(min_heap, (graph[u][v]['weight'], v, u))

    draw_step(graph, pos, mst_edges, visited, None, "MST complete.")
    plt.ioff()
    plt.show()

def main():
    # Create graph
    G = nx.Graph()
    G.add_edge('A', 'B', weight=2)
    G.add_edge('A', 'C', weight=6)
    G.add_edge('A', 'D', weight=1)
    G.add_edge('B', 'D', weight=3)
    G.add_edge('C', 'D', weight=5)

    prim_animated(G, 'A')

if __name__ == "__main__":
    main()
