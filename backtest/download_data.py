import ccxt
from datetime import datetime
import plotly.graph_objects as go
import pandas as pd
import time

def GetData(
    symbol="SOL/USDT",
    timeframe="15m",
    exchange_id="binance",
    since: str = "2025-01-01T00:00:00Z",
) -> pd.DataFrame:

    exchange: ccxt.Exchange = getattr(ccxt, exchange_id)({"enableRateLimit": True})

    since_ms = exchange.parse8601(since)
    tf_ms    = exchange.parse_timeframe(timeframe) * 1000
    limit    = 1000
    all_ohlcv = []

    print(f"Baixando {symbol} [{timeframe}] a partir de {since}")

    while True:
        batch = exchange.fetch_ohlcv(symbol, timeframe, since=since_ms, limit=limit)

        if not batch:
            break

        all_ohlcv += batch
        last_ts = batch[-1][0]
        print(f"  → {len(all_ohlcv)} candles  |  último: {pd.to_datetime(last_ts, unit='ms')}")

        if len(batch) < limit:
            break

        since_ms = last_ts + tf_ms
        time.sleep(exchange.rateLimit / 1000)

    dates, open_data, high_data, low_data, close_data, volume_data = [], [], [], [], [], []

    for candle in all_ohlcv:                          # <-- corrigido
        dates.append(datetime.utcfromtimestamp(candle[0] / 1000.0).strftime('%Y-%m-%d %H:%M:%S'))
        open_data.append(candle[1])
        high_data.append(candle[2])
        low_data.append(candle[3])
        close_data.append(candle[4])
        volume_data.append(candle[5])

    df = pd.DataFrame({
        "datetime": dates,
        "open":     open_data,
        "high":     high_data,
        "low":      low_data,
        "close":    close_data,
        "volume":   volume_data,
    })
    df.to_csv("4h.csv", index=False)            

    fig = go.Figure(data=[go.Candlestick(
        x=dates,
        open=open_data, high=high_data,
        low=low_data,   close=close_data,
    )])
    fig.show()

    return df


def main():
    df = GetData("SOL/USDT", "4h")

if __name__ == "__main__":
    main()