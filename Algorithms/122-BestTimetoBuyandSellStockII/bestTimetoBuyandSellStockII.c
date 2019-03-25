//
// Created by zyc on 3/25/19.
//

#include <zconf.h>
#include "bestTimetoBuyandSellStockII.h"

/*
int maxProfit(int* prices, int pricesSize)
{
    if(prices == NULL || pricesSize < 2)
        return 0;

    int i, j, price = 0;
    bool flag = false;

    for(i = 0; i < pricesSize - 1; i++)
    {
        j = i;
        while(prices[i] < prices[i + 1])
        {
            flag = true;
            i++;
            if(i == pricesSize - 1)
                return price += prices[pricesSize - 1] - prices[j];
        }
        if(flag)
        {
            flag = false;
            i--;
        }
        if(prices[i] < prices[i + 1])
        {
            //printf("%d %d %d %d %d\n", i, j, prices[i], prices[i + 1], prices[j]);
            price += (prices[i + 1] - prices[j]);
        }
    }

    return price;
}
*/

int maxProfit(int* prices, int pricesSize)
{
    if(prices == NULL || pricesSize < 2)
        return 0;

    int cumulativeGain = 0;
    int lastVal = prices[0];

    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] > lastVal)
            cumulativeGain += prices[i] - lastVal;

        lastVal = prices[i];
    }

    return cumulativeGain;
}

int maxProfit_main()
{

    return 0;
}