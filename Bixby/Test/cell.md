# cell 정리

layout > section > content  > cell-card(cell-area).

card와 area는 `slot1`, `slot2`, `slot3` 총 3개의 slot을 가지고 있다.

1부터 차례대로 왼쪽, 가운데, 오른쪽에 표현된다.



## cell-area

![area](./asset/cell/cell-area.png)

```bixby
cell-area {
  slot1 {
    image {
      shape (Circle)
      url ("https://example.com")
    }
  }
  slot2 {
    content {
      primary ("cell-area")
      secondary ("cell-area")
    }
  }
  slot3 {
    image {
      shape (Square)
      url ("https://example.com")
    }
  }
}
```



## cell-card

![card](./asset/cell/cell-card.png)

```bixby
cell-card {
  slot1 {
    image {
      shape (Square)
      url ("https://example.com")
    }
  }
  slot2 {
    content {
      order (SecondaryPrimary)
      primary ("cell-card")
      secondary ("cell-card")
    }
  }
  slot3 {
    image {
      shape (Circle)
      url ("https://example.com")
    }
  }
}
```



## 비교

![cell](./asset/cell/cell.png)

> card는 배경이 있는 것을 알 수 있다.