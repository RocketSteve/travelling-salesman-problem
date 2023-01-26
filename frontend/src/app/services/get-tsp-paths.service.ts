import {Injectable} from '@angular/core';
import {WebsocketService} from "./websocket.service";
import {environment} from "../../environments/environment";
import {Subject} from "rxjs";

@Injectable({
  providedIn: 'root'
})
export class GetTspPathsService {

  public greedySolution: Subject<number[]> = new Subject<number[]>();
  public greedyDistance: Subject<number> = new Subject<number>();
  public saSolution: Subject<number[]> = new Subject<number[]>();
  public saDistance: Subject<number> = new Subject<number>();

  constructor(private websocketService: WebsocketService) {
    this.websocketService.connect(environment.wsUrl).subscribe({
      next: (msg) => {
        const order: string[] = msg.split(' ');
        if (order[0] == "Greedy:") {
          order.shift();
          this.greedyDistance.next(parseInt(order[order.length - 1]));
          order.pop();
          this.greedySolution.next(order.map((x: string) => parseInt(x)));
        } else {
          order.shift();
          this.saDistance.next(parseInt(order[order.length - 1]));
          order.pop();
          this.saSolution.next(order.map((x: string) => parseInt(x)));
        }
      }
      ,
      error: (err) => {
        console.log(err);
      }
      , complete: () => {
        console.log('complete');
      }
    });
  }

  sendInstance(instance: string) {
    this.websocketService.subject.next(instance);
  }
}
