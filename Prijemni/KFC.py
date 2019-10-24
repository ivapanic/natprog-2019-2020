import sys

def main():
    m_meat, s_soy, h_bread = map(float, input().split())
    pm_kn, ps_kn = map(float, input().split())

    if h_bread == 0:
        max_earnings = 0
        print(max_earnings)
    elif m_meat == 0 and s_soy == 0:
        max_earnings = 0
        print(max_earnings)
    else:
        is_there_any_meat = m_meat > 0
        is_there_any_soy = s_soy > 0

        if not is_there_any_meat:
            pm_kn = 0
        elif not is_there_any_soy:
            ps_kn = 0    

        more_expensive = m_meat if not is_there_any_soy or pm_kn > ps_kn else s_soy
        better_price = pm_kn if more_expensive == m_meat else ps_kn

        cheaper = s_soy if more_expensive == m_meat else m_meat
        worse_price = ps_kn if more_expensive == m_meat else pm_kn
        is_there_enough_bread = h_bread >= m_meat + s_soy
        if is_there_enough_bread:
            max_earnings = more_expensive*better_price + cheaper*worse_price
        elif h_bread <= more_expensive:
            max_earnings = h_bread*better_price
        else:
            max_earnings = more_expensive*better_price + (h_bread-more_expensive)*worse_price
        print(int(max_earnings) if float(max_earnings).is_integer() else max_earnings)

    

if __name__ == "__main__":
    main()

