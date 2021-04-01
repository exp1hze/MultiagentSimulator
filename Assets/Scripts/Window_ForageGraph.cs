using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using CodeMonkey.Utils;

public class Window_ForageGraph : MonoBehaviour
{

    [SerializeField] private Sprite circleSprite;
    [SerializeField] private RectTransform graphContainer;
    [SerializeField] private RectTransform labelTemplateX;
    [SerializeField] private RectTransform labelTemplateY;
    [SerializeField] private RectTransform dashTemplateX;
    [SerializeField] private RectTransform dashTemplateY;
    public GameObject[] circles;

    private void Awake()
    {
        //List<int> valueList = new List<int>() { 5, 98, 56, 45, 30, 22, 17, 15, 13, 17, 25, 37, 40, 36, 33 };
        //ShowGraph(valueList, (int _i) => "Day "+(_i+1), (float _f) => "$" + Mathf.RoundToInt(_f));
    }

    public float maxY;
    public void createG_foodin(ArrayList valueList)
    {
        circles = new GameObject[valueList.Count];
        float max = 0f;
        List<float> vl = new List<float>();
        foreach (string t in valueList)
        {
            float food = float.Parse(t);
            if (food > max)
            {
                max = food;
            }
            vl.Add(food);
        }
        //maxY = (int)Math.Ceiling(max);
        //Debug.Log(max + " " + maxY);
        maxY = max;
        ShowGraph(vl, (int _i) => "" + (_i), (float _f) => "" + Mathf.RoundToInt(_f));
    }

    public void createG_numactors(ArrayList valueList)
    {
        circles = new GameObject[valueList.Count];
        float max = 0f;
        List<float> vl = new List<float>();
        foreach (string t in valueList)
        {
            float actors = float.Parse(t);
            if (actors > max)
            {
                max = actors;
            }
            vl.Add(actors);
        }
        //maxY = (int)Math.Ceiling(max);
        //Debug.Log(max + " " + maxY);
        maxY = max;
        ShowGraph(vl, (int _i) => "", (float _f) => "" + Mathf.RoundToInt(_f));
    }
    private GameObject CreateCircle(Vector2 anchoredPosition)
    {
        //m_SpriteRenderer = GetComponent<SpriteRenderer>();
        //m_SpriteRenderer.color = Color.red;
        GameObject gameObject = new GameObject("circle", typeof(Image));
        gameObject.transform.SetParent(graphContainer, false);
        gameObject.GetComponent<Image>().sprite = circleSprite;

        RectTransform rectTransform = gameObject.GetComponent<RectTransform>();
        rectTransform.anchoredPosition = anchoredPosition;
        rectTransform.sizeDelta = new Vector2(11, 11);
        rectTransform.anchorMin = new Vector2(0, 0);
        rectTransform.anchorMax = new Vector2(0, 0);
        return gameObject;
    }

    private void ShowGraph(List<float> valueList, Func<int, string> getAxisLabelX = null, Func<float, string> getAxisLabelY = null)
    {
        if (getAxisLabelX == null)
        {
            getAxisLabelX = delegate (int _i) { return _i.ToString(); };
        }
        if (getAxisLabelY == null)
        {
            getAxisLabelY = delegate (float _f) { Debug.Log(_f); return _f.ToString(); };
        }

        float graphHeight = graphContainer.sizeDelta.y;
        float yMaximum = maxY;
        float xSize = 20f;

        GameObject lastCircleGameObject = null;
        for (int i = 0; i < valueList.Count; i++)
        {
            float xPosition = xSize + i * xSize;
            float yPosition = (valueList[i] / yMaximum) * graphHeight;
            GameObject circleGameObject = CreateCircle(new Vector2(xPosition, yPosition));
            circles[i] = circleGameObject;

            if (lastCircleGameObject != null)
            {
                CreateDotConnection(lastCircleGameObject.GetComponent<RectTransform>().anchoredPosition, circleGameObject.GetComponent<RectTransform>().anchoredPosition);
            }
            lastCircleGameObject = circleGameObject;

            RectTransform labelX = Instantiate(labelTemplateX);
            labelX.SetParent(graphContainer, false);
            labelX.gameObject.SetActive(true);
            labelX.anchoredPosition = new Vector2(xPosition, -7f);
            labelX.GetComponent<Text>().text = getAxisLabelX(i);
            try
            {
                if (int.Parse(getAxisLabelX(i)) % 2 == 1)
                {
                    labelX.GetComponent<Text>().text = "";
                }
            }
            catch (Exception e) { }
            RectTransform dashX = Instantiate(dashTemplateX);
            dashX.SetParent(graphContainer, false);
            dashX.gameObject.SetActive(true);
            dashX.anchoredPosition = new Vector2(xPosition, -3f);
            dashX.transform.SetSiblingIndex(1);
        }

        int separatorCount = 10;
        for (int i = 0; i <= separatorCount; i++)
        {
            RectTransform labelY = Instantiate(labelTemplateY);
            labelY.SetParent(graphContainer, false);
            labelY.gameObject.SetActive(true);
            float normalizedValue = i * 1f / separatorCount;
            labelY.anchoredPosition = new Vector2(-7f, normalizedValue * graphHeight);
            //labelY.GetComponent<Text>().text = getAxisLabelY(normalizedValue * yMaximum);
            labelY.GetComponent<Text>().text = Math.Round(normalizedValue * yMaximum, 2).ToString();

            RectTransform dashY = Instantiate(dashTemplateY);
            dashY.SetParent(graphContainer, false);
            dashY.gameObject.SetActive(true);
            dashY.anchoredPosition = new Vector2(-4f, normalizedValue * graphHeight);
            dashY.transform.SetSiblingIndex(1);
        }
    }

    private void CreateDotConnection(Vector2 dotPositionA, Vector2 dotPositionB)
    {
        GameObject gameObject = new GameObject("dotConnection", typeof(Image));
        gameObject.transform.SetParent(graphContainer, false);
        gameObject.GetComponent<Image>().color = new Color(1, 1, 1, .5f);
        RectTransform rectTransform = gameObject.GetComponent<RectTransform>();
        Vector2 dir = (dotPositionB - dotPositionA).normalized;
        float distance = Vector2.Distance(dotPositionA, dotPositionB);
        rectTransform.anchorMin = new Vector2(0, 0);
        rectTransform.anchorMax = new Vector2(0, 0);
        rectTransform.sizeDelta = new Vector2(distance, 3f);
        rectTransform.anchoredPosition = dotPositionA + dir * distance * .5f;
        rectTransform.localEulerAngles = new Vector3(0, 0, UtilsClass.GetAngleFromVectorFloat(dir));
    }
    public int previousDot = 0;
    public void setcurrentDot(int ts)
    {

        circles[previousDot].GetComponent<Image>().color = Color.white;

        circles[ts].GetComponent<Image>().color = Color.red;
        inWindow(circles[ts]);
        previousDot = ts;

    }

    void inWindow(GameObject circle)
    {
        bool re = false;
        Vector2 center = transform.parent.parent.GetComponent<RectTransform>().position;
        Vector2 acenter = transform.parent.GetComponent<RectTransform>().position;
        //Vector2 self = gameObject.GetComponent<RectTransform>().position;
        Vector2 self = circle.GetComponent<RectTransform>().position;

        float width = transform.parent.parent.GetComponent<RectTransform>().rect.width;
        float height = transform.parent.parent.GetComponent<RectTransform>().rect.height;
        if (self.x <= (center.x + width / 2) && self.x >= (center.x - width / 2))
        {


        }
        else
        {
            float X = acenter.x - self.x + center.x;
            float Y = acenter.y;
            transform.parent.GetComponent<RectTransform>().position = new Vector2(X, Y);
        }

    }

    void setCentral()
    {
        Vector2 center = transform.parent.parent.GetComponent<RectTransform>().position;
        Vector2 acenter = transform.parent.GetComponent<RectTransform>().position;
        Vector2 self = gameObject.GetComponent<RectTransform>().position;
        float X = acenter.x - self.x + center.x;
        float Y = acenter.y - self.y + center.y;
        transform.parent.GetComponent<RectTransform>().position = new Vector2(X, Y);

    }
}
