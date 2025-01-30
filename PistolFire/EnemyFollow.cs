using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyFollows : MonoBehaviour
{
    public GameObject ThePlayer;
    public float TargetDistance;
    public float AllowedRange = 15;
    public GameObject TheEnemy;
    public float EnemySpeed;
    public int AttackTrigger;
    public RaycastHit Shot;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.LookAt(ThePlayer.transform);
        if(Physics.Raycast(transform.position,transform.TransformDirection(Vector3.forward), out Shot))
        {
            TargetDistance = Shot.distance;
            if (TargetDistance < AllowedRange)
            {
                EnemySpeed = 0.015f;
                if(AttackTrigger == 0)
                {
                    TheEnemy.GetComponent<Animation>().Play("Walking");
                    transform.position = Vector3.MoveTowards(transform.position, ThePlayer.transform.position, EnemySpeed);
                }
            }
            else
            {
                EnemySpeed = 0;
                TheEnemy.GetComponent<Animation>().Play("Zombie Idle");
            }
        }
        if(AttackTrigger == 1)
        {
            EnemySpeed = 0;
            TheEnemy.GetComponent<Animation>().Play("Zombie Attack");
        }
    }

    private void OnTriggerEnter()
    {
        AttackTrigger = 1;
    }

    private void OnTriggerExit()
    {
        AttackTrigger = 0;
    }
}
