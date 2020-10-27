using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class Drag : MonoBehaviour, IDragHandler
{

    [SerializeField]
    private Canvas canvas;

    public void OnDrag(PointerEventData evenData)
    {
        gameObject.GetComponent<RectTransform>().anchoredPosition += evenData.delta / canvas.scaleFactor;
    }


    void SetDraggedPosition(PointerEventData evenData)
    {
        var rt = gameObject.GetComponent<RectTransform>();
        Vector3 globalMousePos;
        if (RectTransformUtility.ScreenPointToWorldPointInRectangle(rt, evenData.position, evenData.pressEventCamera
            , out globalMousePos))
        {
            rt.position = globalMousePos;
        }
    }

    public float scale;
    void Start()
    {
        scale = 1f;
    }

    void Update()
    {
        if (Input.GetAxis("Mouse ScrollWheel") > 0)
        {
            if (scale <= 5f)
            {
                scale += 0.2f;
                setScale();
            }
        }
        if (Input.GetAxis("Mouse ScrollWheel") < 0)
        {
            if (scale > 0.5f)
            {
                scale -= 0.2f;
                setScale();
            }
        }
    }

    void setScale()
    {
        gameObject.GetComponent<Transform>().localScale = new Vector3(scale, scale, 1f);
    }
}