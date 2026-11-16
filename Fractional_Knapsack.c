#include <stdio.h>

struct Item
{
    int profit;
    int weight;
    float ratio;
};

void sort(struct Item item[], int n)
{
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(item[i].ratio < item[j].ratio)
            {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(struct Item item[], int n, int capacity)
{
    float totalProfit = 0.0;

    sort(item, n);

    for(int i = 0; i < n; i++)
    {
        if(item[i].weight <= capacity)
        {
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        }
        else
        {
            totalProfit += item[i].profit *
                          ((float)capacity / item[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    for(int i = 0; i < n; i++)
    {
        printf("Profit and Weight of item %d: ", i + 1);
        scanf("%d %d", &item[i].profit, &item[i].weight);

        item[i].ratio =
            (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxProfit =
        fractionalKnapsack(item, n, capacity);

    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}
