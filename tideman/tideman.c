#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    // THIS is executed once for each voter
    // e.g. if ranks[] = [1, 0, 2] if 3 candidates.
    // no of prefs will be count*(count-1)/2
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 1; j < candidate_count; j++)
        {
            if (i < j)
            {
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // iterate over the newly made preferences[][]
    // which has values corresponding to i, j pairs
    // e.g. (cont) pairs[0].winner = 7; pairs[0].loser = 2
    // classify pairs how?
    // preferences[i][j] is no. of voters who prefer i to j
    pair_count = candidate_count * (candidate_count - 1) / 2;
    int pair_counter = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_counter].winner = preferences[i][j];
                pairs[pair_counter].loser = preferences[j][i];
                pair_counter++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // e.g. AB=7,2;CA=6,3; BC=5,4 the graph is A-->B, then C-->A, but B-->C completes the cycle so now we retrace:
    // and C can be traced. somehow.
    // pairs currently looks like [(5,4), (7,2), (6,3)]
    // bigger the difference, the better? they all sum up to voter count
    pair tmp;
    for (int j = 0; j < pair_count; j++)
    {
        int swap_count = 0;
        for (int i = 1; i < pair_count; i++)
        {
            if (pairs[i].winner > pairs[i - 1].winner)
            {
                tmp = pairs[i];
                pairs[i] = pairs[i - 1];
                pairs[i - 1] = tmp;
                swap_count = 1;
            }
        }
        if (swap_count == 0)
        {
            break;
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    // pairs currently looks like [(7,2), (6,3), (5,4)] corresponds with [(0,1), (1,2), (2,0)]
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            for (int k = 0; k < candidate_count; k++)
            {
                if (pairs[i].winner == preferences[j][k])
                {
                    locked[j][k] = true;
                    k = j = candidate_count;
                    continue;
                }
            }
        }
    }
    // now we must identify loops.
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}