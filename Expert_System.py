def prompt_user(prompt: str) -> bool:
    """Prompt the user for a yes/no response."""
    response = input(f"{prompt} (yes/no): ").strip().lower()
    return response == "yes"

def evaluate_market_conditions() -> bool:
    return prompt_user("Is the overall market currently in a bullish trend?")

def evaluate_company_fundamentals() -> bool:
    return prompt_user("Does the company have strong financial fundamentals such as revenue growth and low debt?")

def evaluate_valuation() -> bool:
    return prompt_user("Is the stock considered undervalued compared to its intrinsic value or industry peers?")

def evaluate_trading_volume() -> bool:
    return prompt_user("Is the current trading volume significantly higher than average?")

def evaluate_news_sentiment() -> bool:
    return prompt_user("Has there been recent positive news regarding the company or its sector?")

def evaluate_technical_indicators() -> bool:
    return prompt_user("Are technical indicators such as moving averages or RSI suggesting a buying opportunity?")

def main():
    print("Stock Investment Expert System")
    print("--------------------------------\n")

    score = 0
    total_criteria = 6

    if evaluate_market_conditions():
        print("Market trend is currently positive.")
        score += 1
    else:
        print("Market trend is currently negative or uncertain.")

    if evaluate_company_fundamentals():
        print("Company fundamentals are strong.")
        score += 1
    else:
        print("Company fundamentals are not strong.")

    if evaluate_valuation():
        print("Stock appears to be undervalued.")
        score += 1
    else:
        print("Stock may be overvalued or fairly priced.")

    if evaluate_trading_volume():
        print("Trading volume is above average.")
        score += 1
    else:
        print("Trading volume is below or around average.")

    if evaluate_news_sentiment():
        print("Recent news sentiment is favorable.")
        score += 1
    else:
        print("No recent favorable news identified.")

    if evaluate_technical_indicators():
        print("Technical indicators suggest a buy opportunity.")
        score += 1
    else:
        print("Technical indicators do not suggest buying at this time.")

    print("\nInvestment Recommendation Summary:")
    if score >= 5:
        print("Recommendation: Strong Buy")
    elif score >= 3:
        print("Recommendation: Hold or Monitor Closely")
    else:
        print("Recommendation: Not Recommended for Investment at This Time")

if __name__ == "__main__":
    main()