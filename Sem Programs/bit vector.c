#include<stdio.h>
#include<ctype.h>

char univ_set[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

char set1[26], set2[26];
int bit_vect1[26], bit_vect2[26], result[26];

void display_set(int bit[26]);
void display_array(int bit[26]);

void InitializeSet()
{
    for (int i = 0; i < 26; i++)
    {
        bit_vect1[i] = 0;
        bit_vect2[i] = 0;
        result[i] = 0;
    }
}

void bit_vector(char arr[], int bit[], int size)
{
    for(int i = 0; i < size; i++)
    {
        char c = toupper(arr[i]);
        for(int j = 0; j < 26; j++)
        {
            if(c == univ_set[j])
            {
                bit[j] = 1;
                break;
            }
        }
    }
}

void SetUnion(int bit_vect1[26], int bit_vect2[26])
{
    for (int i = 0; i < 26; i++)
        result[i] = bit_vect1[i] | bit_vect2[i];

    printf("Union : ");
    display_set(result);
    printf("\nBit Vector : ");
    display_array(result);
}

void SetIntersection(int bit_vect1[26], int bit_vect2[26])
{
    for (int i = 0; i < 26; i++)
        result[i] = bit_vect1[i] & bit_vect2[i];

    printf("Intersection : ");
    display_set(result);
    printf("\nBit Vector : ");
    display_array(result);
}

void SetComplement(int bit[26])
{
    for (int i = 0; i < 26; i++)
        result[i] = (bit[i] == 0) ? 1 : 0;

    printf("Complement (Set1): ");
    display_set(result);
    printf("\nBit Vector : ");
    display_array(result);
}

void SetDifference(int bit1[26], int bit2[26])
{
    SetComplement(bit2);
    SetIntersection(bit1, result);

    printf("Set Difference (Set1 - Set2): ");
    display_set(result);
    printf("\nBit Vector : ");
    display_array(result);
}

void display_array(int bit[26])
{
    for (int i = 0; i < 26; i++)
        printf("%d ", bit[i]);
    printf("\n");
}

void display_set(int bit[26])
{
    for (int i = 0; i < 26; i++)
        if (bit[i] == 1)
            printf("%c ", univ_set[i]);
}

int main()
{
    int size1, size2, choice;

    InitializeSet();

    printf("Enter number of elements in Set1: ");
    scanf("%d", &size1);
    printf("Enter elements of Set1: ");
    for (int i = 0; i < size1; i++)
        scanf(" %c", &set1[i]);

    printf("Enter number of elements in Set2: ");
    scanf("%d", &size2);
    printf("Enter elements of Set2: ");
    for (int i = 0; i < size2; i++)
        scanf(" %c", &set2[i]);

    bit_vector(set1, bit_vect1, size1);
    bit_vector(set2, bit_vect2, size2);

    printf("\nBIT VECTOR OF SET 1:\n");
    display_array(bit_vect1);

    printf("BIT VECTOR OF SET 2:\n");
    display_array(bit_vect2);

    do
    {
        printf("\n======= MENU =======\n");
        printf("1. Union\n");
        printf("2. Intersection\n");
        printf("3. Set Difference (Set1 - Set2)\n");
        printf("4. Complement of Set1\n");
        printf("5. Exit\n");

        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: SetUnion(bit_vect1, bit_vect2); 
			break;
			
            case 2: SetIntersection(bit_vect1, bit_vect2);
			break;
			
            case 3: SetDifference(bit_vect1, bit_vect2); 
			break;
			
            case 4: SetComplement(bit_vect1); 
			break;
			
            case 5: printf("Exiting...\n");
			break;
			
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}