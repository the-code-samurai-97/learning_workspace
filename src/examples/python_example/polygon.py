import matplotlib.pyplot as plt
from matplotlib.patches import Polygon

# Coordinates for Polygon A
polygon_a_coords = [
    [-0.90478776881879274807, 0.51756843862589896332],
    [-0.91, 0.48],
    [-1.2, 0.4],
    [-1.4, 1.9],
    [-0.90478776881879274807, 0.51756843862589896332]
]

# Coordinates for Polygon B
polygon_b_coords = [
    [-0.91943242964602156508, 0.55292377741135378955],
    [-0.90478776881879174887, 0.51756843862590162786],
    [-0.91, 0.48],
]

# Coordinates for Polygon C
polygon_c_coords = [
    [-0.91, 0.48],
    [-1.2, 0.4],
    [-1.4, 1.9],
    [-0.904788, 0.517568],
    [-0.904788, 0.517568],
    [-0.91, 0.48],
    [-1.2, 0.4],
    [-1.4, 1.9],
    [-0.904788, 0.517568],
    [-0.91, 0.48],
]

# Plotting
fig, ax = plt.subplots()
ax.set_aspect('equal', adjustable='box')  # Ensure equal aspect ratio

# Plot Polygon A
# polygon_a = Polygon(polygon_a_coords, closed=True, edgecolor='b', facecolor='none')
# ax.add_patch(polygon_a)

# Plot Polygon B
polygon_b = Polygon(polygon_b_coords, closed=True, edgecolor='r', facecolor='none')
ax.add_patch(polygon_b)

# Plot Polygon C
polygon_c = Polygon(polygon_c_coords, closed=True, edgecolor='g', facecolor='none')
ax.add_patch(polygon_c)

# Set axis limits
ax.set_xlim(-1.5, 0)
ax.set_ylim(0, 2)

# Show the plot
plt.show()
