#include <iostream>
#include <array>
#include <random>
#include <ctime>

enum class CardSuit
{
    club,
    diamond,
    heart,
    spade,

    max_suits,
};

enum class CardRank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks,
};

enum class Outcomes
{
    win,
    lose,
    tie,
};

struct Card
{
    CardRank rank{};
    CardSuit suit{};
};

struct Player
{
    int score{};
};

constexpr int g_maxScore{ 21 };
constexpr int g_dealerMinScore{ 17 };

void printCard(const Card& card)
{
    switch (card.rank)
    {
    case CardRank::rank_2:      std::cout << '2';       break;
    case CardRank::rank_3:      std::cout << '3';       break;
    case CardRank::rank_4:      std::cout << '4';       break;
    case CardRank::rank_5:      std::cout << '5';       break;
    case CardRank::rank_6:      std::cout << '6';       break;
    case CardRank::rank_7:      std::cout << '7';       break;
    case CardRank::rank_8:      std::cout << '8';       break;
    case CardRank::rank_9:      std::cout << '9';       break;
    case CardRank::rank_10:     std::cout << 'T';      break;
    case CardRank::rank_jack:   std::cout << 'J';       break;
    case CardRank::rank_queen:  std::cout << 'Q';       break;
    case CardRank::rank_king:   std::cout << 'K';       break;
    case CardRank::rank_ace:    std::cout << 'A';       break;

    default:
        std::cout << '?';
        break;
    }

    switch (card.suit)
    {
    case CardSuit::club:        std::cout << 'C';       break;
    case CardSuit::diamond:     std::cout << 'D';       break;
    case CardSuit::heart:       std::cout << 'H';       break;
    case CardSuit::spade:       std::cout << 'S';       break;

    default:
        std::cout << '?';
        break;
    }
}

std::array<Card, 52> createDeck()
{
    std::array<Card, 52> deck{};
    int index{ 0 };
    for (int suit{ 0 }; suit < static_cast<int>(CardSuit::max_suits); ++suit)
    {
        for (int rank{ 0 }; rank < static_cast<int>(CardRank::max_ranks); ++rank)
        {
            deck[index].rank = static_cast<CardRank>(rank);
            deck[index].suit = static_cast<CardSuit>(suit);
            ++index;
        }
    }

    return deck;
}

void printDeck(std::array<Card, 52>& deck)
{
    for (Card card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffleDeck(std::array<Card, 52>& deck)
{
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};

    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(Card& card)
{
    switch (card.rank)
    {
    case CardRank::rank_2:      return 2;
    case CardRank::rank_3:      return 3;
    case CardRank::rank_4:      return 4;
    case CardRank::rank_5:      return 5;
    case CardRank::rank_6:      return 6;
    case CardRank::rank_7:      return 7;
    case CardRank::rank_8:      return 8;
    case CardRank::rank_9:      return 9;
    case CardRank::rank_10:     return 10;
    case CardRank::rank_jack:   return 10;
    case CardRank::rank_queen:  return 10;
    case CardRank::rank_king:   return 10;
    case CardRank::rank_ace:    return 11;

    default:
        return 0;
    }
}

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "Do you want to hit or stand (h/s)? ";
        char choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 'h': 
            return true;
        case 's': 
            return false;
        }
    }
}

bool playerTurn(std::array<Card, 52>& deck, int index, Player& player)
{
    while (true)
    {
        if (player.score > g_maxScore)
        {
            std::cout << "You've gone bust!\n";
            return true;
        }
        else
            if (playerWantsHit())
            {
                Card& card{ deck[++index] };
                player.score += getCardValue(card);
                std::cout << "You were dealt a ";
                printCard(card);
                std::cout << " and now have a score of " << player.score << '\n';
            }
            else
            {
                return false;
            }
    }
}

bool dealerTurn(std::array<Card, 52>& deck, int index, Player& dealer)
{
    while (dealer.score < g_dealerMinScore)
    {
        Card& card{ deck[++index] };
        dealer.score += getCardValue(card);
        std::cout << "The dealer got a ";
        printCard(card);
        std::cout << " and now has a score of " << dealer.score << '\n';
    }

    if (dealer.score > g_maxScore)
    {
        std::cout << "The dealer's gone bust!\n";
        return true;
    }

    return false;
}


Outcomes playBlackJack(std::array<Card, 52>& deck)
{
    static int deckIndex{ 0 };

    Player dealer{ getCardValue(deck[deckIndex]) + getCardValue(deck[++deckIndex]) };
    std::cout << "The dealer is showing a ";
    printCard(deck[deckIndex]);
    std::cout << '\n';

    Player player{ getCardValue(deck[++deckIndex]) + getCardValue(deck[++deckIndex]) };
    std::cout << "You have a score of " << player.score << '\n';

    if (playerTurn(deck, deckIndex, player))
    {
        return Outcomes{ Outcomes::lose };
    }

    if (dealerTurn(deck, deckIndex, dealer))
    {
        return Outcomes{ Outcomes::win };
    }

    if (player.score > dealer.score)
        return Outcomes{ Outcomes::win };
    else if (player.score < dealer.score)
        return Outcomes{ Outcomes::lose };
    else
        return Outcomes{ Outcomes::tie };
}

int main()
{
    auto deck{ createDeck() };
    shuffleDeck(deck);

    Outcomes gameOutcome{ playBlackJack(deck) };

    switch (gameOutcome)
    {
    case Outcomes::win:
    {
        std::cout << "You win!\n";
        break;
    }
    case Outcomes::lose:
    {
        std::cout << "You lose.\n";
        break;
    }
    case Outcomes::tie:
    {
        std::cout << "It's a tie!\n";
        break;
    }

    default:
        std::cout << "???\n";
        break;
    }

    return 0;
}

